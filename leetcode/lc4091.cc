// LC4091. Count Magical Substring Pairs II
// LeetCode Biweekly Contest 195 Q4

/*
   You are given a string `s` of length `n` consisting of lowercase English letters.

   For every triplet of indices `{i, j, k}` satisfying `0 <= i <= j < k < n`, define:

   - `s1 = s[i..k]`
   - `s2 = s[j + 1..k]`

   A pair of substrings `(s1, s2)` is called magical if the number of distinct characters in `s1` is equal to the number of distinct characters in `s2`.

   Return the number of triplets `(i, j, k)` for which `(s1, s2)` is a magical pair.

   A substring is a contiguous non-empty sequence of characters within a string.
*/

/*
   Example1:\
   Input: s = "aba"\
   Output: 2\
   Explanation:

   There are 2 valid triplets:

   | No. | `(i, j, k)` | `s1` | `s2` | `distinct(s1)` | `distinct(s2)` |
   | - | - | - | - | - | - |
   | 1 | (0,0,1) | "a" | "b" | 1 | 1 |
   | 2 | (1,1,2) | "b" | "a" | 1 | 1 |

   Example2:\
   Input: s = "kkk"\
   Output: 4

   Example3:\
   Input: s = "abcac"\
   Output: 7
*/

/*
   Constraints:

   - `2 <= s.length <= 10^5`
   - `s`a consists of lowercase English letters.
*/

#include <algorithm>
#include <array>
#include <string>
#include <vector>
class Solution {
private:
    std::vector<std::array<int, 27>> calc(const std::string& s) {
        int n = s.size();

        std::vector<std::array<int, 27>> f(n);

        for (int k = 1; k <= 26; ++k) {
            int cnt[26] = {};
            int l = 0;
            int distinct = 0;

            for (int r = 0; r < n; ++r) {
                if (cnt[s[r] - 'a']++ == 0) {
                    ++distinct;
                }

                while (distinct > k) {
                    if (--cnt[s[l++] - 'a'] == 0) --distinct;
                }

                f[r][k] = r - l + 1;
            }
        }

        return f;
    }

public:
    long long countMagicalPairs(std::string s) {
        int n = s.size();
        auto left = calc(s);
        std::string zorelquima = s;
        std::reverse(s.begin(), s.end());
        auto right = calc(s);
        long long ans = 0;

        for (int j = 0; j < n - 1; ++j) {
            int r = n - 2 - j;

            for (int k = 1; k <= 26; ++k) {
                long long a = left[j][k] - left[j][k - 1];
                long long b = right[r][k] - right[r][k - 1];

                ans += a * b;
            }
        }

        return ans;
    }

};
