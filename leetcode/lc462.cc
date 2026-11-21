// LC462. Minimum Moves to Equal Array Elements II

/*
   Given an integer array `nums` of size `n`, return the minimum number of moves required to manke all array elements equal.

   In one move, you can increment or decrement an element of the array by `1`.

   Test cases are designed so that the answer will fit in a 32-bit integer.
*/

/*
   Example1:\
   Input: nums = [1.2.3]\
   Output: 2

   Example2:\
   Input: nums = [1,10,2,9]\
   Output: 16
*/

/*
   Constraints:

   - `n == nums.length`
   - `1 <= nums.length <= 10^5`
   - `-10^9 <= nums[i] <= 10^9`
*/

#include <algorithm>
#include <cstdlib>
#include <vector>
// 这道题有了I的前车之鉴，很容易想到找一个数作为参照，这个数需要符合变动小，我第一次想到的是平均数，平均数在数据总体平均，极值不明显的样本中是对的，但是一旦最大值和最小值差别过大或者一个数特别大，其他数都很小，这种情况就不对了，后来我想到了中位数，因为我想到：一个国家的平均工资或许不低，但是大多数的工资是低于平均工资的，因为九成的财富掌握在一成人的手中，而中位数就能够反映出这种样本模型下多数数据的情况
class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int res = 0;

        std::sort(nums.begin(), nums.end());
        int mid = nums[n / 2];

        for (int num : nums) res += abs(mid - num);

        return res;
    }
};
