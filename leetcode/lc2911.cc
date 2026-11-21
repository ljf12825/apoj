// LC2911. Minimum Changes to Make K Semi-palindromes

/*
   Given a string `s` and an integer `k`, partition `s` into `k` substrings such that the letter changes needed to make each substring a semi-palindrome are minimized.

   Return the minimum number of letter changes required.

   A semi-palindrome is a special type of string that can be divided into palindromes based on a repeating pattern. To check if a string is a semi-palindrome:

   1. Choose a positive divisor `d` of the string's length. `d` can range fromm `1` up to, but not including, the string's length. For a string of length `1`, it does not have a valid divisor as per this definition, since the only divisor is its length, which is not allowed.
   2. For a given divisor `d`, divide the string into groups where each group contains characters from the string that follow a repeating pattern of length `d`. Specifically, the first group consists of characters at positions `1`, `1 + d`, `1 + 2d`, and son on; the second group includes characters at positions `2`, `2 + d`, `2 + 2d`, etc.
   3. The string is considered a semi-palindrome if each of these groups forms a palindrome.

   Consider the string `"abcabc"`:

   - The length of `"abcabc"` is `6`. Valid divisors are `1`, `2`, and `3`.
   - For `d = 1`: The entire string `"abcabc"` forms one group. Not a palindrome.
   - For `d = 2`:
     - Group1(positions `1, 3, 5`): `"abc"`
     - Group2(positions `2, 4, 6`): `"bac"`
     - Neither group forms a palindrome.
   - For `d = 3`:
     - Group1(positions `1, 4`): `"aa"`
     - Group2(positions `2, 5`): `"bb"`
     - Group3(positions `3, 6`): `"cc"`
     - All groups form palindromes. Therefore, `"abcabc"` is a semi-palindrome.
*/

/*
   Example1:\
   Input: s = "abcac", k = 2\
   Output: 1

   Example2:\
   Input: s = "abcdef", k = 2\
   Output: 2

   Example3:\
   Input: s = "aabbaa", k = 3\
   Output: 0
*/

/*
   Constraints:

   - `2 <= s.length <= 200`
   - `1 <= k <= s.length/ 2`
   - `s` contains only lowercase English letters.
*/

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int minimumChanges(std::string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        std::vector<std::vector<int>> divs(n + 1);
        for (int d = 1; d <= n; ++d) {
            for (int multiple = d * 2; multiple <= n; multiple += d) {
                divs[multiple].push_back(d);
            }
        }

        std::vector<std::vector<int>> cost(n, std::vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int L = j - i + 1;
                int min_ops = L;
                for (int d : divs[L]) {
                    int ops = 0;
                    for (int r = 0; r < d; ++r) {
                        int l_ptr = i + r;
                        int r_ptr = j - d + 1 + r;
                        while (l_ptr < r_ptr) {
                            if (s[l_ptr] != s[r_ptr]) ++ops;
                            l_ptr += d;
                            r_ptr -= d;
                        }
                    }

                    min_ops = std::min(min_ops, ops);
                }

                cost[i][j] = min_ops;
            }
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, INF));
        dp[0][0] = 0;

        for (int j = 1; j <= k; ++j) {
            for (int i = j * 2; i <= n; ++i) {
                for (int p = (j - 1) * 2; p <= i - 2; ++p) {
                    dp[i][j] = std::min(dp[i][j], dp[p][j - 1] + cost[p][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
