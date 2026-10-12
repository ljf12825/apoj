// LC16. 3Sum Closest

/*
   You are given an integer array `nums` of length `n` and an integer `target`.

   Find three integers at distinct indices in `nums` such that the sum is closest to `target`.

   Return the sum of the three integers.

   You may assume that each input would have exactly one solution.
*/

/*
   Example1:\
   Input: nums = [-1,2,1,-4], target = 1\
   Output: 2\
   Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

   Example2:\
   Input: nums = [0,0,0], target = 1\
   Output: 0\
   Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
*/

#include <algorithm>
#include <cstdlib>
#include <vector>
// 这道题和15题是一样的，比15题还要简单些
class Solution {
public:
    int threeSumClosest(std::vector<int>&nums, int target) {
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int bestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(sum - target) < abs(bestSum - target)) bestSum = sum;

                if (sum == target) return sum;
                else if (sum < target) ++left;
                else --right;
            }
        }

        return bestSum;
    }
};
