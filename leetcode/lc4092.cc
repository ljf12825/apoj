// LC4092. Binary Digit Score
// LeetCode Weekly Contest 525 Q1

/*
   You are given two integers `a` and `b`.

   Let `s1` and `s2` be the number of set bits in the binary representations of `a` and `b`, respectively.

   The score of these integers is defined as follows:

   - If `s1 >= s2`, the score is `s1 * s2`
   - Otherwise, the score is `s2 / s1` using integer division.

   Return an integer representing the score of `a` and `b`.

   A set bit refers to a bit in the binary representation of a number that has a value of 1.
*/

/*
   Example1:\
   Input: a = 14. b = 6\
   Output: 6

   Example2:\
   Input: a = 5, b = 15\
   Output: 2

   Example3:\
   Input: a = 10, b = 12\
   Output: 4
*/

/*
   Constraints:

   - `1 <= a, b <= 100`
*/

class Solution {
public:
    int calculateScore(int a, int b) {
        int res = 0;
        int resa = calchelper(a);
        int resb = calchelper(b);

        res = (resa >= resb) ? resa * resb : resb / resa;

        return res;
    }

private:
    int calchelper(int temp) {
        int sum = 0;
        while (temp > 0) {
            sum += temp % 2;
            temp /= 2;
        }

        return sum;
    }
};
