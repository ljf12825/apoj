// LC4105. Repeated String Match II
// LeetCode Biweekly Contest 195 Q4

/*
   You are given two strings `a` and `b` consisting of lowercase English letters, and two integers `x` and `y`.

   Return `true` if the string formed by repeating `b` exactly `y` time (`b * y`) is a substring of the string formed by repeating `a` exactly `x` times (`a * x`).\
   Otherwise, return `false`
*/

/*
   Example1:\
   Input: a = "ab", b = "abab", x = 2, y = 1\
   Output: true

   Example2:\
   Input: a = "abc", b = "bc", x = 2, y = 3\
   Output: false

   Example3:\
   Input: a = "abcd", b = `cdab`, x = 1, y = 1\
   Output: true
*/

/*
   Constraints:

   - `1 <= a.length <= 100`
   - `1 <= b.length <= 100`
   - `1 <= x <= 10^9`
   - `1 <= y <= 10^9`
   - `a` and `b` consist of lowercase English letters.
*/
