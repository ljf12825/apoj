// LC5. Longest Palindromic Substring

/*
   Given a string `s`, return the longest palindromic substring in `s`
*/

/*
   Example1:
   Input: s = "babab"
   Output: "bab"

   Example2:
   Input: s = "cbbd"
   Output: "bb"
*/

#include <string>
#include <vector>
#include <map>
// Solution1 暴力解法：1. 找疑似回文串的子串左右边界，2. 判断子串是否是回文串，3. 如果是回文串放入map，4. 取最大长度对应的字符串；最坏时间复杂度O(n^3)
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() == 1 || s.length() == 0) return s;
        int i = 0;
        std::map<int, std::string> table;
        while (i < s.size()) {
            std::vector<int> vec = searchright(i, s);
            for (auto j : vec) {
                if (ispalindromic(i, j, s)) {
                int length = j - i + 1;
                std::string ss = s.substr(i, length);
                table.insert({length, ss});
                }
            }
            ++i;
        }
        if (table.empty()) return s.substr(0, 1);
        else return table.rbegin()->second;
    }

    bool ispalindromic(int i, int j, const std::string& s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }

        return true;
    }

    std::vector<int> searchright(int i, const std::string& s) {
        std::vector<int> vec;
        int j = i + 1;
        while (j < s.size()) {
            if (s[i] == s[j]) vec.push_back(j);
            ++j;
        }

        return vec;
    }
};
