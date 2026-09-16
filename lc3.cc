// LC3. Longest Substring Without Repeating Characters

/*
   Given a string `s`, find the length of the longest substring without duplicate characters.
*/

/*
   Example1:
   Input: s = "abcabcbb"
   Output: 3
   Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

   Example2:
   Input: s = "bbbbb"
   Output: 1

   Example3:
   Input: s = "pwwkew"
   Output: 3
*/

// Solution1 暴力解法 时间复杂度O(n^2 * m)
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        for (int i = 0; i < s.length(); ++i) {
            string ss;
            for (int j = i; j < s.length(); ++j) {
                if (ss.find(s[j]) == string::npos) {
                    ss.push_back(s[j]);
                } else break;
            }
            length = length > ss.length() ? length : ss.length();
        }

        return length;
    }
};
