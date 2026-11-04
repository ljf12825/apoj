// LC453. Minimum Moves to Equal Array Elements

/*
   You are given an integer array `nums` of size `n`.

   Return the minimum number of moves required to make all array elements equal.

   In one move, you must increment `n - 1` elements of the array by 1.
*/

/*
   Example1:\
   Input: nums = [1,2,3]\
   Output: 3

   Example2:\
   Input: nums = [1,1,1]\
   Output: 0
*/

/*
   Constraints:

   - `n == nums.length`
   - `1 <= nums.length <= 10^5`
   - `-10^9 <= nums[i] <= 10^9`
*/

#include <algorithm>
#include <vector>

// Solution0：最开始的思路，直接正向求解，先对传入nums排序，然后找到最大的，这个是不加1的数字，其他的数依次加1，然后再排序，循环以上结果，直到所有元素相等，这个解法TLE，`std::sort`的时间复杂度是O(n log n)的，每次循环内再sort时间复杂度非常高
class Solution0 {
public:
    int minMoves(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        if (n == 1 || n == 0 || nums[0] == nums[n - 1]) return 0;

        int i = 0;
        while (nums[0] != nums[n - 1]) {
            for (int j = 0; j < n - 2; ++j) {
                nums[j] += 1;
            }

            ++i;

            std::sort(nums.begin(), nums.end());
        }

        return i;
    }
};
