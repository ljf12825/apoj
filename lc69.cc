// LC69.Sqrtx

/*
   Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer. The return integer. The returned integer should be non-negative as well.

   You must not use any built-in exponent function or operator

   - For example, do not use `pow(x, 0.5)` in C++ or `x ** 0.5` in Python
   Example 1:
   Input: x = 4
   Output: 2
   Explanation: The square root of 4 is 2, so we return 2.

   Example 2:
   Input: x = 8
   Output: 2
   Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

   `0 <= x < 2^31 - 1`
*/

// 方法1
// 该问题可转化为 求 n^2 <= x，求n的最大值
// 使用二分查找

class Solution1 {
public:
  int mySqrt(int x) {
    int left = 0, right = x / 2, mid = 0;
    while (left <= right) {
      mid = (left + right) / 2;
      if ((long long)mid * mid < x) left = mid + 1;
      else right = mid - 1;
    }

    if ((long long) left * left > x) left -= 1;
    return left;
  }
};

// 方法2
// 使用指数函数和对数函数替代平方根函数
// sqrt(x)可以变换为 e^(0.5lnx)

#include <cmath>
class Solution2 {
public:
  int mySqrt(int x) {
    if (x == 0) return 0;
    int ans = exp(0.5 * log(x));
    return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans); // 计算机无法存储准确的浮点数，需要判断正确答案
  }
};

// 方法3
// 牛顿迭代
class Solution_3 {
public:
  int mySqrt(int x) {
    if (x == 0)
      return 0;

    double C = x, x0 = x;
    while (true) {
      double xi = 0.5 * (x0 + C / x0);
      if (fabs(x0 = xi) < 1e-7)
        break;
      x0 = xi;
    }
    return int(x0);
  }
};
