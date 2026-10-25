// LC4088. Difference Between Peaks and Valleys
// LeetCode Biweekly Contest 195 Q1

/*
   You are given an integer array `nums` of length `n`.

   An index `i` is called a peak if all of the following conditions hold:

   - `0 < i < n - 1`
   - `nums[i] > nums[i - 1]`
   - `nums[i] > nums[i + 1]`

   An index `i` is called a valley if all of the following conditions hold:

   - `0 < i < n - 1`
   - `nums[i] < nums[i - 1]`
   - `nums[i] < nums[i + 1]`

   Return an integer denoting the difference between the sum of all peak values and the sum of all valley values
*/

/*
   Example1:\
   Input: nums = [1,5,2,4,1,3,0]\
   Output: 9\
   Explanation:

   - The peak values are `nums[1] = 5`, `nums[3] = 4`, and `nums[5] = 3`.
   - The valley values are `nums[2] = 2` and `nums[4] = 1`.
   - The difference between the sum of the peak values and the sum of the valley values if `(5 + 4 + 3) - (2 + 1) = 9`. Hence, the answer is 9.

   Example2:\
   Input: nums = [-5,-6,-1,-2,5,3,2]\
   Output: 12

   Example3:\
   Input: nums = [6,5,2,5,5,3,6]\
   Output: -5
*/

/*
   Constraints:

   - `3 <= n == nums.length <= 100`
   - `-100 <= nums[i] <= 100`
*/

#include <vector>

class Solution {
public:
    int peakValleyDifference(std::vector<int>& nums) {
        int n = nums.size() - 1;
        int i = 1;
        int sum = 0;
        while (i < n) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) sum += nums[i];
            if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) sum -= nums[i];
        }

        return sum;
    }
};
