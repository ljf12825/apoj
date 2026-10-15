// LC2913. Subarrays Distinct Element Sum of Squares I

/*
   You are given a 0-indexed integer array `nums`.

   The distinct count of a subarray of `nums` is defined as:

   - Let `nums[i..j]` be a subarray of `nums` consisting of all the indices from `i` to `j` such that `0 <= i <= j < nums.length`. Then the number of distinct value in `nums[i..j]` is called the distinct count of `nums[i..j]`.

   Return the summary of the squares of distinct counts of all subarray of `nums`.

   A subarray is a contiguous non-empty sequence of elements within an array.
*/

/*
   Example1:\
   Input: nums = [1,2,1]\
   Output: 15\
   Explanation: Six possible subarrays are:\
   [1]: 1 distinct value\
   [2]: 1 distinct value\
   [1]: 1 distinct value\
   [1,2]: 2 distinct values\
   [2,1]: 2 distinct values\
   [1,2,1]: 2 distinct values\
   The sum of the squares of the distinct counts in all subarray is equal to 1^2 + 1^2 + 1^2 + 1^2 + 2^2 + 2^2 = 15

   Example2:\
   Input: nums = [1,1]\
   Output: 3
*/
