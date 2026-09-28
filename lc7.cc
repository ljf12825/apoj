// LC7. Reverse Integer

/*
   Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`

   Assume the environment does not allow you to store 64-bit integers(signed or unsigned).
*/

/*
   Example1:\
   Input: x = 123\
   Output: 321

   Example2:\
   Input: x = -123\
   Output: -321

   Example3:\
   Input: x = 120\
   Output: 21
*/

#include <climits>
#include <cstdlib>
#include <vector>

// Solution0：这是我最开始的解法，大体思路是有的，但是很多决策错误导致踩了很多坑，所以值得记下来，虽然可以修补正确，但已经绕的太远了
// signed int32的范围是[-2^31, 2^31 - 1]，即[-2147483648, 2147483647]
// 常见误区是对signed int32进行取绝对值操作时，abs(-2147483648)会导致整型溢出，这也被叫做`INT_MIN`的对称性陷阱
class Solution0 {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int flag = x < 0 ? -1 : 1; // 没必要
        int xabs = abs(x); // 可能产生溢出
        std::vector<int> vec;
        int i = 0;
        int bit = 1;
        int result = 0;

        while (xabs > 0) {
            vec.push_back(xabs % 10);
            xabs /= 10;
        }

        if (vec[0] == 0) { // 我选择的中间表示方法和结果表示方法导致我必须这么做
            while (i < vec.size() && vec[i] == 0) {
                ++i;
            }
            vec.erase(vec.begin(), vec.begin() + i);
        }

        if (vec.size() > 31) return 0; // 这是没有必要的，因为给出的x最多10位，这里是跟二进制位搞串了
        else {
            for (auto x = vec.rbegin(); x != vec.rend(); ++x) {
                if (result > INT_MAX - (*x) * bit) return 0;
                else result += (*x) * bit; // 这并不是一种好的计算方式，这也就导致产生一大堆的边界情况
                if (*x != 0 && bit > INT_MAX / ((*x) * 10)) return 0;
                if (bit > INT_MAX / 10) return 0;
                else bit *= 10;
            }
        }

        return result * flag;
    }

};

// Solution1：按位取出并重组
class Solution1 {
public:
    int reverse(int x) {
        std::vector<int> vec;

        while (x != 0) {
            vec.push_back(x % 10);
            x /= 10;
        }

        int result = 0;

        for (int digit : vec) { // 对于所有可能产生溢出的位置都需要提前验证
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return 0;

            result = result * 10 + digit;
        }

        return result;
    }
};

// Solution2：标准解法；其实不需要引入vector，直接取一位，组合一位
class Solution2 {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MAX / 10 && pop < -8)) return 0;

            result += result * 10 + pop;
        }

        return result;
    }
};
