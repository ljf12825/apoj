// LC136. Single Number

/*
   Given a non-empty array of integers `nums`, every element appears twice except for one. Find that single one.

   You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

/*
   Example1:\
   Input: nums = [2,2,1]\
   Output: 1

   Example2:\
   Input: nums = [4,1,2,1,2]\
   Output: 4

   Example3:\
   Input: nums = [1]\
   Output: 1
*/

#include <vector>
// 本题要求O(n)时间复杂度，O(1)空间复杂度，那只有XOR一种解法
// x ^ 0 = x, x ^ x = 0, x ^ y = y ^ x, (x ^ y) ^ z = x ^ (y ^ z)
// 以 Example2 为例：4 ^ 1 ^ 2 ^ 1 ^ 2 = 4 ^ (1 ^ 1) ^ (2 ^ 2) = 4
class Solution {
public:
    int singleNumber(std::vector<int> nums) {
        int result = 0;

        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};
