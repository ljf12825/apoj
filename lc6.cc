// LC6. Zigzag Conversion

/*
   The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given numvver of rows like this:(you may want to display this pattern in a fixed font for better legibility)
   ```txt
   P A H N
   APLSIIG
   Y I R
   ```

   And then read line by line: `"PAHNAPLSIIGYIR"`

   Write the code that will take a string and make this conversion given a number of rows:

   `string convert(string s, int numRows);`
*/

/*
   Example1:\
   Input: s = "PAYPALISHIRING", numRows = 3\
   Output: "PAHNAPLSIIGYIR"

   Example2:\
   Input: s = "PAYPALISHIRING", numRows = 4\
   Output: "PINALSIGYAHRPI"\
   Explanation:

   ```txt
   P  I  N
   A LS IG
   YA HR
   P  I
   ```
*/

#include <string>
#include <vector>
// Solution1：维护一个二维数组，构造震荡数列，确定每一个字符的实际位置并写入
class Solution1 {
public:
    std::string convert(std::string s, int numRows) { // 整体时间复杂度接近O(n * numRows)
        if (numRows == 1 || numRows >= s.size()) return s;
        std::vector<std::vector<char>> vecx;
        int vnum = 0;
        int cnum = 0;
        std::string ss;
        std::vector<int> pos = getpos(s.size(), numRows);

        while (cnum < s.size()) {
            std::vector<char> vecy(numRows);
            vecx.push_back(vecy);
            vecx[vnum][pos[cnum]] = s[cnum];
            ++cnum;
            ++vnum;
        }
        /*
           这最终构造出来的是
           P   A   H   N
            A P L S I I G
             Y   I   R

           虽然结果正确，但是程序效率低，每个vecy只利用了一个元素，占用n x numRows个`char`空间
           同时这也说明，空白位置并不影响结果，只要保证同一行中字符前后顺序就可以
        */

        for (int i = 0; i < numRows; ++i) { // 时间复杂度为O(numRows)
            for (int j = 0; j < vnum; ++j) {
                if (vecx[j][i]) ss.push_back(vecx[j][i]);
            }
        }

        return ss;
    }

    std::vector<int> getpos(int length, int numRows) { // 本题的核心就是生成震荡数列 时间复杂度为O(n)
        int x = 0;
        int dir = 1;
        std::vector<int> vec;

        for (int i = 0; i < length; ++i) {
            vec.push_back(x);
            x += dir;

            if (x == numRows - 1) dir = -1;
            else if (x == 0) dir = 1;
        }

        return vec;
    }
};

// Solution2：根据Solution1的分析，可以将算法优化为维护一个vector<string>，最后拼接所有的string就可以，字符在numRows个string里震荡存入

class Solution2 {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        std::vector<std::string> rows(numRows);
        int row = 0;
        int dir = 1;

        for (char c : s) {
            rows[row].push_back(c);

            if (row == 0) dir = 1;
            else if (row == numRows - 1) dir = -1;

            row += dir;
        }

        std::string ans;
        
        for (auto& row : rows) ans += row;

        return ans;
    }
};
