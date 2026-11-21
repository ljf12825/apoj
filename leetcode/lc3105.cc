// LC3105. Longest Strictly Increasing or Strictly Decreasing Subarray

/*
   You are given an array of integers `nums`. Return the length of the longest subarray of `nums` which is either strictly increasing or strictly decreasing.
*/

/*
   Example1:\
   Input: nums = [1,4,3,3,2]\
   Output: 2

   Example2:\
   Input: nums = [3,3,3,3]\
   Output: 1

   Example3:\
   Input: nums = [3,2,1]\
   Output: 3
*/

/*
   Constraints:

   - `1 <= nums.length <= 50`
   - `1 <= nums[i] <= 50`
*/

#include <algorithm>
#include <vector>

class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        int res = 1, tres1 = 1, tres2 = 1;
        int n = nums.size();

        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] < nums[i + 1]) {
                ++tres1;
                res = std::max(res, tres1);
            } else tres1 = 1;
        }

        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] > nums[i + 1]) {
                ++tres2;
                res = std::max(res, tres2);
            } else tres2 = 1;
        }

        return res;
    }
};
