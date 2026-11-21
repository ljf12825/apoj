// LC4093. Maximize Sum After At Most K Digit Rearrangements
// LeetCode Weekly Contest 525 Q2

/*
   You are given an integer array `nums` of length `n` and an integer `k`.

   In one operation, you may choose any element of `nums` and rearrange its decimal digits in any order to form a new integer.

   Return the maximum possible sum of the array after performing at most `k` operations.
*/

/*
   Example1:\
   Input: nums = [123,45], k = 1\
   Output: 366

   Example2:\
   Input: nums = [102,90,14], k = 2\
   Output: 341
*/

/*
   Constraints:

   - `1 <= n == nums.length <= 10^5`
   - `1 <= nums[i] <= 10^9`
   - `1 <= k <= n`
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximizeSum(std::vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        std::vector<std::tuple<long long, long long, int>> vec;
        vec.reserve(n);

        for (int num : nums) {
            long long r = rearrange(num);
            vec.emplace_back(r - num, r, num);
        }
        
        std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return get<0>(a) > get<0>(b);
        });

        for (int i = 0; i < n; ++i) {
            res += (i < k) ? get<1>(vec[i]) : get<2>(vec[i]);
        }

        return res;
    }
private:
    static long long rearrange(int x) {
        long long res = 0;
        int count[10] = {0};
        while (x > 0) { count[x % 10]++; x /= 10; }
        for (int d = 9; d >= 0; --d) {
            while (count[d]--) res = res * 10 + d;
        }

        return res;
    }
};
