// LC4103. Remove Elements by Type and Color
// LeetCode Biweekly Contest 195 Q2

/*
   You are given three integer arrays `types`, `colors`, and `groupSize`, where `types` and `colors` have length `n`, and `groupSize` has length `m`.

   - `types[i]` represents the type of the element at index `i`.
   - `colors[i]` represents the color of the element at index `i`.
   - `groupSize[t]` represents the required number of elements in a removable group of type `t`.

   In one operation, you may remove exactly `groupSize[t]` consecutive elements if all of them have type `t` and the same color.

   After each removal, the remaining elements become adjacent again while maintaining their relative order.

   Return `true` if it is possible to remove all elements using a sequence of valid operations. Otherwise, return `false`.
*/

/*
   Example1:\
   Input: types = [0,1,1,0], colors = [5,3,3,5], groupSize = [2,2]\
   Output: true

   Example2:\
   Input: types = [0,1,0], colors = [9,9,9], groupSize = [3,2]\
   Output: false

   Example3:\
   Input: types = [2,0,1,2], colors = [7,5,4,7], groupSize = [3,1,2]\
   Output: false
*/

/*
   Constraints:

   - `1 <= n == types.length == colors.length <= 10^5`
   - `1 <= m == groupSize.length <= 10^5`
   - `0 <= types[i] <= m - 1`
   - `1 <= colors[i] <= 10^5`
   - `1 <= groupSize[t] <= n`
*/
