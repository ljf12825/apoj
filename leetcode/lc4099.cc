// LC4099. Minimum Operations to Sort With Locked Indices
// LeetCode Weekly Contest 526 Q3

/*
   You are given an integer array `nums` of length `n`, where `nums` is a permutation of the integers in the range `[1, n]`.

   You are also given a binary array `locked` of length `n` and an integer `k`.

   - `locked[i] = 1` means index `i` is locked.
   - `locked[i] = 0` means index `i` is unlocked.

   You may perform the following operations in any order:

   - Swap: Choose an index `i` such that both indices `i` and `i + 1` are currently unlocked, and swap `nums[i]` and `nums[i + 1]`.
   - Unlock: Choose an index `i` such that `locked[i] = 1` and permanently unlock it by setting `locked[i] = 0`.

   You may perform any number of swap operations but at most `k` unlock operations.

   Return the minimum total number of operations required to sort `nums` in strictly increasing order. If it is impossible, return -1.
*/

/*
   Example1:\
   Input: nums = [2,1,3,4], locked = [0,1,0,1], k = 1\
   Output: 2

   Example2:\
   Input: nums = [3,1,2], locked = [1,0,1], k = 2\
   Output: 4

   Example3:\
   Input: nums = [2,3,1], locked = [1,0,0], k = 0\
   Output: -1
*/

/*
   Constraints:

   - `1 <= n == nums.length == locked.length <= 2000`
   - `1 <= nums[i] <= n`
   - `0 <= locked[i] <= 1`
   - `nums` is a permutation of the integers in the range `[1,n]`.
   - `0 <= k <= n`
*/

/*
   Can you solve this in `O(nlog(n))`?
*/
