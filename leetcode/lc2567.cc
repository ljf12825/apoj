// LC2567. Minimum Score by Changing Two Elements

/*
   You are given an integer array `nums`:

   - The low score of `nums` is the minimum absolute difference between any two integers.
   - The high score of `nums` is the maximum absolute difference between any two integers.
   - The score of `nums` is the sum of the high and low scores.

   Return the minimum score after changing two elements of `nums`.
*/

/*
   Example1:\
   Input: nums = [1,4,7,8,5]\
   Output: 3

   Example2:\
   Input: nums = [1,4,3]\
   Output: 0
*/

/*
   Constraints:

   - `3 <= nums.length <= 10^5`
   - `1 <= nums[i] <= 10^9`
*/

#include <algorithm>
#include <climits>
#include <vector>

// 本题难在推理和证明
// Solution1
class Solution1 {
public:
    int minimizeSum(std::vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        return std::min({nums[n - 1] - nums[2], nums[n - 3] - nums[0], nums[n - 2] - nums[1]});
    }
};

// Solution2：优化版，O(n)时间，O(1)空间，在一个for循环里同时维护6个极值
class Solution2 {
public:
    int minimizeSum(std::vector<int>& nums) {
        int s1 = INT_MAX, s2 = INT_MAX, s3 = INT_MAX, l1 = 0, l2 = 0, l3 = 0;
        for (int n : nums) {
            if (s1 > n) { s3 = s2; s2 = s1; s1 = n; }
            else if (s2 > n) { s3 = s2; s2 = n; }
            else if (s3 > n) { s3 = n; }

            if (l1 < n) { l3 = l2; l2 = l1; l1 = n; }
            else if (l2 < n) { l3 = l2; l2 = n; }
            else if (l3 < n) { l3 = n; }
        }

        return std::min({l1 - s3, l3 - s1, l2 - s2});
    }
};
