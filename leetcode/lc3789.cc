// LC3789. Minimum Cost to Acquire Required Items

/*
   You are given five integers `cost1`, `cost2`, `costBoth`, `need1`, and `need2`.

   There are three types of items avaliable:

   - An item of type 1 costs `cost1` and contributes 1 unit to the type 1 requirement only.
   - An item of type 2 costs `cost2` and contributes 1 unit to the type 1 requirement only.
   - An item of type 3 costs `costBoth` and contributes 1 unit to both type 1 and type 2 requirement.

   You must collect enough items so that the total contribution toward type 1 is at least `need1` and total contribution toward type 1 is at least `need2`.

   Return an integer representing the minimum possible total cost to achieve these requirements.
*/

/*
   Example1:\
   Input: cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2\
   Output: 3

   Example2:\
   Input: cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3\
   Output: 22

   Example3:\
   Input: cost1 = 5, cost2 = 4, costBoth = 15, need1 = 0, need2 = 0\
   Output: 0
*/

/*
   Constraints:

   - `1 <= cost1, cost2, costBoth <= 10^5`
   - `0 <= need1, need2 <= 10^9`
*/

#include <algorithm>
// 时间复杂度O(1)，空间复杂度O(1)
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {
        long long both = std::min(need1, need2);

        long long ans = both * std::min(costBoth, cost1 + cost2);

        if (need1 > need2) {
            ans += 1LL * (need1 - need2) * std::min(cost1, costBoth);
        } else {
            ans += 1LL * (need2 - need1) * std::min(cost2, costBoth);
        }

        return ans;
    }
};

