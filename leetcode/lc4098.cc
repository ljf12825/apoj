// LC4098. Minimize the Maximum Value of GCD-Connected Array
// LeetCode Weekly Contest 526 Q2

/*
   You are given three integers `n`, `index` and `value`.

   An integer array `nums` of length `n` is called GCD-Connected if:

   - `nums[i] > 0` for `0 <= i <= n - 1`.
   - `nums[i] < nums[i + 1]` for `0 <= i <= n - 2`.
   - `nums[index] = value`.
   - `gcd(nums[i], nums[i + 1]) > 1` for `0 <= i <= n - 2`

   Return the minimum possible maximum value, `nums[n - 1]`, among all GCD-Connected arrays `nums`. If no such array exists, return -1.
*/

/*
   Example1:\
   Input: n = 4, index = 2, value = 8\
   Output: 10

   Example2:\
   Input: n = 2, index = 1, value = 3\
   Output: -1

   Example3:\
   Input: n = 2, index = 0, value = 3\
   Output: 6
*/

/*
   Constraints:

   - `2 <= n <= 10^9`
   - `1 <= value <= 10^9`
   - `0 <= index <= n - 1`
*/
