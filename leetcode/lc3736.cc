// LC3736. Minimum Moves to Equal Array Elements III

/*
   You are given an integer array `nums`.

   In one move, you may increase the value off any single element `nums[i]` by 1.

   Return the minimum total number of moves required so that all elements in `nums` become euqal.
*/

/*
   Example1:\
   Input: nums = [2,1,3]\
   Output: 3

   Example2:\
   Input: nums = [4,4,5]\
   Output: 2
*/

/*
   Constraints:

   - `1 <= nums.length <= 100`
   - `1 <= nums[i] <= 100`
*/

#include <algorithm>
#include <vector>

// 这题相比I和II简单，直接模拟就可以解决
class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        int maxval = *std::max_element(nums.begin(), nums.end());
        int res = 0;

        for (int num : nums) res += maxval - num;

        return res;
    }
};
