// LC3041. Maximize Consecutive Elements in an Array After Modification

/*
   You are given a 0-indexed array `nums` consisting of positive integers.

   Initially, you can increase the value of any element in the array by at most `1`.

   After that, you need to select one or more elements from the final array such that those elements are consecutive when sorted in increasing order. For example, the elements `[3, 4, 5]` are consecutive while `[3, 4, 6]` and `[1, 1, 2, 3]` are not.

   Return the maximum number of elements that you can select.
*/

/*
   Example1:\
   Input: nums = [2,1,5,1,1]\
   Output: 3

   Example2:\
   Input: nums = [1,4,7,10]\
   Output: 1
*/

/*
   Constraints:

   - `1 <= nums.length <= 10^5`
   - `1 <= nums[i] <= 10^6`
*/
