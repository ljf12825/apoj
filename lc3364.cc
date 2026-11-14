// LC3364. Minimum Positive Sum Subarray

/*
   You are given an integer array `nums` and two integers `l` and `r`. Your task is to find the minimum sum of a subarray whose size is between `l` and `r`(inclusive) and whose sum is greater than 0.

   Return the minimum sum of such a subarray. If no such subarray exists, return -1.

   A subarray is a contiguous non-empty sequence of elements within an array.
*/

/*
   Example1:\
   Input: nums = [3,-2,1,4], l = 2, r = 3\
   Output: 1

   Example2:\
   Input: nums = [-2,2,-3,1], l = 2, r = 3\
   Output: -1

   Example3:\
   Input: nums = [1,2,3,4], l = 2, r = 4\
   Output: 3
*/

/*
   Constraints:

   - `1 <= nums.length <= 100`
   - `1 <= l <= r <= nums.length`
   - `-1000 <= nums[i] <= 1000`
*/
