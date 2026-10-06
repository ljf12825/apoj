// LC12. Integer to Roman

/*
    Seven different symbols represent Roman numerals with the following values:

    | Symbol | Value |
    | - | - |
    | I | 1 |
    | V | 5 |
    | X | 10 |
    | L | 50 |
    | C | 100 |
    | D | 500 |
    | M | 1000 |

    Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

    - If the value not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
    - If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (`I`) less than 5 (`V`): `IV` and 9 is 1 (`I`) less than 10 (`X`): `IX`. Only the following subtractive forms are used: 4(`IV`), 9(`IX`), 40(`XL`), 90(`XC`), 400(`CD`) and 900(`CM`).
    - Only power of 10(`I`, `X`, `C`, `M`) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5(`V`), 50(`L`), or 500(`D`) multiple times. If you need to append a symbol 4 times use the subtractive form.

    Given an integer, convert it to a Roman numeral.
*/


/*
    Example1:\
    Input: num = 3749\
    Output: "MMMDCCXLIX"

    Example2:\
    Input: num = 1994\
    Output: "MCMXCIV"

    Example3:\
    Input: num = 58\
    Output: "LVIII"
*/

// Solution1：我的不优雅算法
#include <string>
#include <utility>
#include <vector>

class Solution1 {
public:
    std::string intToRoman(int num) {
        std::string s;
        
        // 1000
        int mnum = 0;
        if (num >= 1000) {
            mnum = num / 1000;
            num = num - 1000 * mnum;
        }

        // 900
        bool cmflag = false;
        if (num >= 900) {
            cmflag = true;
            num -= 900;
        }

        // >= 500
        int dcnum = 0;
        bool dflag = false;
        if (num < 900 && num >= 500) {
            dflag = true;
            dcnum = (num - 500) / 100;
            num = num - dcnum * 100 - 500;
        }

        // >= 400 && < 500
        bool cdflag = false;
        if (num < 500 && num >= 400) {
            cdflag = true;
            num -= 400;
        }

        // >= 100 && < 400
        int cnum = 0;
        if (num < 400 && num >= 100) {
            cnum = num / 100;
            num -= cnum * 100;
        }

        // 9x
        bool xcflag = false;
        if (num < 100 && num >= 90) {
            xcflag = true;
            num -= 90;
        }

        // < 90 && >= 50
        int lxnum = 0;
        bool lflag = false;
        if (num < 90 && num >= 50) {
            lflag = true;
            lxnum = (num - 50) / 10;
            num = num - 50 - lxnum * 10;
        }

        // 4x
        bool xlflag = false;
        if (num >= 40 && num < 50) {
            xlflag = true;
            num -= 40;
        }

        // >= 10 && < 40
        int xnum = 0;
        if (num >= 10 && num < 40) {
            xnum = num / 10;
            num -= xnum * 10;
        }

        // 9
        bool ixflag = false;
        if (num == 9) {
            ixflag = true;
            num = 0;
        }

        bool vflag = false;
        int vinum = 0;
        if (num >= 5 && num < 9) {
            vflag = true;
            vinum = num - 5;
            num = 0;
        }

        bool ivflag = false;
        if (num == 4) {
            ivflag = true;
            num = 0;
        }

        int inum = 0;
        if (num < 4) {
            inum = num;
            num = 0;
        }

        while (mnum--) s.push_back('M');
        if (cmflag) {
            s.push_back('C');
            s.push_back('M');
        }
        if (dflag) {
            s.push_back('D');
            while (dcnum--) s.push_back('C');
        }
        if (cdflag) {
            s.push_back('C');
            s.push_back('D');
        }
        while (cnum--) s.push_back('C');
        if (xcflag) {
            s.push_back('X');
            s.push_back('C');
        }
        if (lflag) {
            s.push_back('L');
            while (lxnum--) s.push_back('X');
        }
        if (xlflag) {
            s.push_back('X');
            s.push_back('L');
        }
        while (xnum--) s.push_back('X');
        if (ixflag) {
            s.push_back('I');
            s.push_back('X');
        }
        if (vflag) {
            s.push_back('V');
            while (vinum--) s.push_back('I');
        }
        if (ivflag) {
            s.push_back('I');
            s.push_back('V');
        }
        while (inum--) s.push_back('I');

        return s;
    }
};

// Solution2 贪心查表法，标准优雅解法
class Solution2 {
public:
    std::string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> table = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        std::string res;
        for (auto& [value, symbol] : table) {
            if (num == 0) break;
            while (num >= value) {
                res += symbol;
                num -= value;
            }
        }

        return res;
    }

};
