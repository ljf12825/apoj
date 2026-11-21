// LC3420. Count Non-Decreasing Subarrays Afer K Operrations

/*
   You are given an array `nums` of `n` integers and an integer `k`.

   For each subarray of `nums`, you can apply up to `k` operations on it.\
   In each operation you increment any element of the subarray by 1.

   Note that each subarray is considered independently, meaning changes made to one subarray do not persist to another.

   Return the number of subarrays that you can make non-decreasing after performing at most `k` operations.

   An array is said to be non-decreasing if each element is greater than or equal to its previous element, if it exists.
*/

/*
   Example1:\
   Input: nums = [6,3,1,2,4,4], k = 7\
   Output: 17

   Example2:\
   Input: nums = [6,3,1,3,6], k = 4\
   Output: 12

*/

/*
   Constraints:

   - `1 <= nums.length <= 10^5`
   - `1 <= nums[i] <= 10^9`
   - `1 <= k <= 10^9`
*/

#include <deque>
#include <utility>
#include <vector>

class Solution {
public:
    long long countNonDecreasingSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;

        std::deque<std::pair<int, int>> dq;

        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            int val = nums[l];
            int cnt = 1;

            while (!dq.empty() && dq.front().first <= val) {
                auto [front_val, front_cnt] = dq.front();
                dq.pop_front();
                cost += 1LL * (val - front_val) * front_cnt;
                cnt += front_cnt;
            }
            dq.push_front({val, cnt});

            while (cost > k) {
                auto& [back_val, back_cnt] = dq.back();
                cost -= (back_val - nums[r]);
                --back_cnt;
                if (back_cnt == 0) dq.pop_back();
                --r;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
