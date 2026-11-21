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

#include <algorithm>
#include <string>
#include <vector>

// Solution1 暴力解法 时间复杂度O(n^2 * m)
class Solution1 {
public:
    int lengthOfLongestSubstring(std::string s) {
        int length = 0;
        for (int i = 0; i < s.length(); ++i) {
            std::string ss;
            for (int j = i; j < s.length(); ++j) {
                if (ss.find(s[j]) == std::string::npos) {
                    ss.push_back(s[j]);
                } else break; // 直接跳出循环，清空ss的内容
            }
            length = length > ss.length() ? length : ss.length();
        }

        return length;
    }
};

// Solution2 滑动窗口：优化暴力解法，不清除窗口改为往后移动，这样可以减少重复动作
class Solution2 {
public:
    int lengthOfLongestSubstring(std::string s) {
        int ans = 0;
        int left = 0;

        std::vector<int> last(256, -1);

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];

            if (last[c] >= left) { // 隐式类型转换，如果字符串只包含ASCII字符(0~127)，安全；
                left = last[c] + 1; // 一旦发现last[c]的值不是-1，说明之前有这个字符，那就把left移动到这个字符后面
            }

            last[c] = right; // 记录每个char的位置

            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};
