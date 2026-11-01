// LC4097. Minimum Value of Merged Integers

/*
   You are given an integer array `nums` of even length `n`.

   You have to merge the element of `nums` in pairs by merging `nums[0]` with `nums[1]`, `nums[2]`, `nums[3]`, and so on, until `nums[n - 2]` with `nums[n - 1]`.

   Return the minimum value among all the resulting merged integers.

   To merge two integers, concatenate all the decimal digits of the first integer followed by all the dicimal digits of the second integer.
*/

/*
   Example1:\
   Input: nums = [23,55,42,21]\
   Output: 2355

   Example2:\
   Input: nums = [34,7,11,11]\
   Output: 347

   Example3:\
   Input: nums = [9,20]\
   Output: 920
*/

/*
   Constraints:

   - `2 <= n == nums.length <= 100`
   - `n` is even
   - `1 <= nums[i] <= 1000`
*/
