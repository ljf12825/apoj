// LC4090. Count Magical Substring Pairs I
// LeetCode Biweekly Contest 195 Q3

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

   - `2 <= s.length <= 2000`
   - `s`a consists of lowercase English letters.
*/

#include <algorithm>
#include <string>
class Solution {
public:
    int countMagicalPairs(std::string s) {
        int n = s.size();
        int res = 0;

        for (int j = 0; j + 1 < n; ++j) {
            int distleft[27] = {0};
            int appear[26] = {0};
            int pos = 0;
            for (int i = j; i >= 0; --i) {
                int c = s[i] - 'a';
                if (appear[c]++ == 0) ++pos;
                distleft[pos]++;
            }

            int distright[27] = {0};
            std::fill(appear, appear + 26, 0);
            pos = 0;
            for (int k = j + 1; k < n; ++k) {
                int c = s[k] - 'a';
                if (appear[c]++ == 0) ++pos;
                distright[pos]++;
            }

            for (int x = 1; x <= 26; ++x) res += distleft[x] * distright[x];
        }

        return res;
    }
};
