// LC3693. Climbing Stairs II

/*
   You are climbing a staircase with `n + 1` steps, numbered from 0 to `n`

   You are also given a 1-indexed integer array `costs` of length `n`, where `costs[i]` is the cost of step `i`.

   From step `i`, you can jump only to step `i + 1`, `i + 2`, or `i + 3`.\
   The cost of jumping from step `i` to step `j` is defined as: `costs[j] + (j - i)^2`

   You start from step 0 with `cost = 0`.

   Return the minimum total cost to reach step `n`
*/

/*
   Example1:\
   Input: n = 4, costs = [1,2,3,4]\
   Output: 13\
   Explanation: `0 -> 1 -> 2 -> 4`

   Example2:\
   Input: n = 4, costs = [5,1,6,2]\
   Output: 11\
   Explanation: `0 -> 2 -> 4`

   Example3:\
   Input: n = 3, costs = [9,8,3]\
   Output: 12\
   Explanation: `0 -> 3`
*/

/*
   Constraints:

   - `1 <= n == costs.length <= 10^5`
   - `1 <= costs[i] <= 10^4`
*/

#include <algorithm>
#include <climits>
#include <vector>
// Solution1：迭代DP，时间复杂度O(n)
class Solution1 {
public:
    int climbStairs(int n, std::vector<int>& costs) {
        const long long INF = LLONG_MAX / 2;
        std::vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            long long c = costs[i - 1];

            for (int d = i; d <= 3; ++d) {
                if (i - d >= 0) dp[i] = std::min(dp[i], dp[i - d] + c + 1LL * d * d);
            }
        }

        return (int)dp[n];
    }
};

// Solution2：空间优化，滚动三个变量
