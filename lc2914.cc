// LC2914. Minimum Number of Changes to Make Binary String Beautiful

/*
   You are given a 0-indexed binary string `s` having an even length.

   A string is beautiful if it's possible to partition it into one or more substrings such that:

   - Each substring has an even length.
   - Each substring contains only `1`'s or only `0`'s.

   You can change any character in `s` to `0` or `1`.

   Return the minimum number of changes required to make the string `s` beautiful.
*/

/*
   Example1:\
   Input: s = "1001"\
   Output: 2

   Example2:\
   Input: s = "10"\
   Output: 1

   Example3:\
   Input: s = "0000"\
   Output: 0
*/

/*
   Constraints:

   - `2 <= s.length <= 10^5`
   - `s` has an even length.
   - `s[i]` is eigher `'0'` or `'1'`.
*/
