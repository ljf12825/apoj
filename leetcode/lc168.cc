// LC168. Excel Sheet Column Title

/*
   Given an integer `columnNumber`, return its corresponding column title as it appears in an Excel sheet.

   For example:

   ```txt
   A -> 1
   B -> 2
   C -> 3
   ...
   Z -> 26
   AA -> 27
   AB -> 28
   ...
   ```
*/

/*
   Example1:\
   Input: columnNumber = 1\
   Output: "A"

   Example2:\
   Input: columnNumber = 28\
   Output: "AB"

   Example3:\
   Input: columnNumber = 701\
   Output: "ZY"
*/

/*
   Constraints:\
   - `1 <= columnNumber <= 2^31 - 1`
*/

#include <algorithm>
#include <string>
// Solution1：递归，本质是26进制，但是没有0，每次需要先--
class Solution1 {
public:
    std::string convertToTitle(int columnNumber) {
        if (columnNumber == 0) return "";
        columnNumber--;
        return convertToTitle(columnNumber / 26) + char('A' + columnNumber % 26);
    }
};

// Solution2：迭代
class Solution2 {
public:
    std::string convertToTitle(int columnNumber) {
        std::string res;
        while (columnNumber > 0) {
            columnNumber--;
            res += char('A' + columnNumber % 26);
            columnNumber /= 26;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
