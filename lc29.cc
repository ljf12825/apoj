// LC29. Divide Two Integers

/*
   Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division, and mod operator.

   The integer division should truncate toward zero, which means losing its fractional part. For example, `8.345` would be truncated to `8`, and `-2.7335` would be truncated to `-2`.

   Return the quotient after dividing `dividend` by `divisor`.

   Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: `[-2^31, 2^31 - 1]`. For this problem, if the quotient is strictly greater than `2^31 - 1`, then return `2^31 - 1`, and if the quotient is strictly less than `-2^31`, then return `-2^31`.
*/

/*
   Example1:\
   Input: dividend = 10, divisor = 3\
   Output: 3

   Example2:\
   Input: dividend = 7, divisor = -3\
   Output: -2
*/

/*
   Constraints:\

   - `-2^31 <= dividend, divisor <= 2^31 - 1`
   - `divisor != 0`
*/

#include <climits>
#include <cstdlib>
// Solution1：我的解法，加减法模拟，大量if-else特例判断，特别是对INT_MIN的判断
class Solution1 {
public:
    int divide (int dividend, int divisor) {
        if (dividend == 0) return 0;

        int res = 0;

        if (dividend == INT_MIN) {
            if (divisor == 1) return INT_MIN;
            else if (divisor == -1) return  INT_MAX;
            else if (divisor == INT_MIN) return 1;
            else {
                if (divisor > 0) {
                    while (dividend <= 0) {
                        dividend += divisor;
                        res++;
                    }

                    return -res + 1;
                } else {
                    while (dividend <= 0) {
                        dividend -= divisor;
                        res++;
                    }

                    return res - 1;
                }
            }
        }

        if (divisor == INT_MIN) return 0;

        int absdividend = abs(dividend);
        int absdivisor = abs(divisor);

        bool flag = false;

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) flag = true;
        if (absdividend == absdivisor) return flag ? -1 : 1;
        if (absdivisor == 1) return flag ? -absdividend : absdividend;
        if (absdividend < absdivisor) return 0;
        else {
            while (absdividend >= 0) {
                absdividend -= absdivisor;
                res++;
            }

            if (flag) return -res + 1;
            else return res - 1;
        }
    }
};

// Solution2：倍增优化，每次不是减去一个divisor，而是减去2^k个divisor；把所有数字都转换成负数，因为int的负数范围比正数大1，能统一处理正负情况
class Solution2 {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == 0) return 0;

        bool negative = (dividend < 0) ^ (divisor < 0);

        int a = dividend < 0 ? dividend : -dividend;
        int b = divisor < 0 ? divisor : -divisor;

        int res = 0;

        while (a <= b) {
            int tmp = b;
            int multiple = 1;

            while (tmp >= a - tmp && multiple < (1 << 30)) {
                tmp += tmp;
                multiple += multiple;
            }

            a -= tmp;
            res += multiple;
        }

        return negative ? -res : res;
    }
};
