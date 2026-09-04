// LC70. Climbing Stairs

/*
   You are climbing a staircase. It takes `n` steps to reach the top.

   Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

   Example1:
   Input: n = 2
   Output: 2
   Explanation: There are two ways to climb to the top.\
   1. 1 step + 1 step
   2. 2 steps

   Example2:
   Input: n = 3
   Output: 3
   Explanation: There are three ways to climb to the top\
   1. 1 step + 1 step + 1 step
   2. 1 step + 2 steps
   3. 2 steps + 1 step

   `1 <= n <= 45`
*/

#include <unordered_map>

// 方法一：递归
class Solution1 {
private:
    std::unordered_map<int, int> table = {
        {1, 1},
        {2, 2}
    };

public:
    int climbStairs(int n) {
        auto it = table.find(n);
        if (it != table.end()) return it->second;

        int sum = climbStairs(n - 1) + climbStairs(n - 2);
        table[n] = sum;

        return sum;
    }
};

// 方法二：迭代

/*
   f(1) = 1
   f(2) = 2

   i = 3
   f(3) = 1 + 2 = 3
   
   i = 4
   f(4) = 2 + 3 = 5

   i = 5
   f(5) = 3 + 5 = 8

   f(n) 只依赖 f(n-1)和f(n-2)

   所以只保存两个变量就可以了

   | a | b | sum |
   | - | - | - |
   | 1 | 2 | 3 |
   | 2 | 3 | 5 |
   | 5 | 8 | 13 |
*/

class Solution2 {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int a = 1;
        int b = 2;

        for (int i = 3; i <= n; ++i) {
            int sum = a + b;
            a = b;
            b = sum;
        }

        return b;
    }
};
















