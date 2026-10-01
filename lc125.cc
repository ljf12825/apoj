// LC125. Valid Palindrome

/*
   A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. *Alphanumeric characters include letters and numbers*.

   Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.
*/

/*
   Example1:\
   Input: s = "A man, a plan, a canal: Panama"\
   Output: true\
   Explanation: "amanaplanacanalpanama" is a palindrome.

   Example2:\
   Input: s = "race a car"\
   Output: false\

   Example3:\
   Input: s = ""\
   Output: true
*/

#include <cctype>
#include <string>

class Soluion {
public:
    bool isPalindrome(std::string s) { // 这题逻辑上没什么新东西
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if ((s[i] < 48 || s[i] > 57) && (s[i] < 65 || s[i] > 90) && (s[i] < 97 || s[i] > 122)) { // 0-9, a-z, A-Z
                ++i;
                continue;
            }
            if ((s[j] < 48 || s[j] > 57) && (s[j] < 65 || s[j] > 90) && (s[j] < 97 || s[j] > 122)) {
                --j;
                continue;
            }

            // 上面的一长串判断可以替换为
            // if (!std::isalnum(s[i]));
            // if (!std::isalnum(s[j]));

            if (tolower(s[i]) != tolower(s[j])) return false;
        }

        return true;
    }
};
