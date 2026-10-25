// LC4089. Count Subarrays With Loose Bounds
// LeetCode Biweekly Contest 195 Q1

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
