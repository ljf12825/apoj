// LC4089. Count Subarrays With Loose Bounds
// LeetCode Biweekly Contest 195 Q2

/*
   You are given an integer array `nums` and two integers `minK` and `maxK`.

   A loose-bound subarray is a subarray in which every elements is greater than or equal to `minK` and less than or equal to `maxK`.

   Return the number of loose-bound subarrays in `nums`.

   A subarray is a contiguous non-empty sequence of elements within an array.
*/

/*
   Example1:\
   Input: nums = [1,4,7,3], minK = 1, maxK = 5\
   Output: 4

   Example2:\
   Input: nums = [1,1], minK = 1, maxK = 1\
   Output: 3
*/

/*
   Constraints:

   - `2 <= nums.length <= 10^5`
   - `1 <= nums[i], minK, maxK <= 10^6`
*/

#include <vector>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int n = nums.size();
        if (n == 0) return res;

        int i = 0;
        int j = 0;

        while (i < n) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                j = i;
                i++;
                while (i < n && nums[i] >= minK && nums[i] <= maxK) ++i;

                long long len = i - j;
                j = i;
                res += (len * (len + 1)) / 2;
            } else { ++i; ++j; }
        }

        return res;
    }
};
