// LC4094. Count Frequency Staircase Subarrays I
// LeetCode Weekly Contest 525 Q3

/*
   You are given an integer array `nums`.

   Consider the distinct values of a subarray in the order in which they first appear.

   If there are `k` distinct values, the subarray is called a frequency staircase if the first distinct value occurs exactly once, the second distinct value occurs exactily twice, and so on, with the `kth` distinct value occurring exactly `k` times.

   Equivalently, the frequencies of the distinct values, in the order of their first occurrence, must be exactly `1, 2, 3, ..., k`.

   Return the number of frequency staircase subarrays in `nums`.

   A subarray is a contiguous non-empty sequence of elements within an array.

   The frequency of a value in a subarray is the number of times it occurs in that subarray.
*/

/*
   Example1:\
   Input: nums = [5,8,8,2,2,2]\
   Output: 9\
   Explanation:

   Every single-element subarray has frequencies `[1]`, and there are 6 of them. 3 longer subarrays also qualify:

   | Subarray | Values by first appearance | Frequencies |
   | - | - | - |
   | `nums[0...2] = [5, 8, 8]` | 5, then 8 | [1,2] |
   | `nums[2...4] = [8, 2, 2]` | 8, then 2 | [1,2] |
   | `nums[0...5] = [5, 8, 8, 2, 2, 2]` | 5, then 8, then 2 | [1,2,3] |

   Example2:\
   Input: nums = [6,6,9,9]\
   Output: 5

   Example3:\
   Input: nums = [2,3,4,4,3,4]\
   Output: 8
*/

/*
   Constraints:

   - `1 <= nums.length <= 1500`
   - `1 <= nums[i] <= 10^5`
*/
