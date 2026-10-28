// LC3882. Minimum XOR Path in a Grid

/*
   You are given a 2D intger array `grid` of size `m * n`.

   You start at the top-left cell `(0,0)` and want to reach the bottom-right cell `(m - 1, n - 1)`

   At each setp, you may move either right or down.

   The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.

   Return the minimum possible XOR value among all valid paths from `(0,0)` to `(m - 1, n - 1)`.
*/

/*
   Example1:\
   Input: grid = [[1,2], [3,4]]\
   Output: 6\
   Explanation:\

   There are two valid paths:

   - `(0,0) -> (0,1) -> (1,1)` with XOR: `1 XOR 2 XOR 4 = 7`
   - `(0,0) -> (1,0) -> (1,1)` with XOR: `1 XOR 3 XOR 4 = 6`

   The minimum XOR value among all valid paths is 6.

   Example2:\
   Input: grid = [[6,7], [5,8]]\
   Output: 9

   Example3:\
   Input: grid = [[2,7,5]]\
   Output: 0
*/

/*
   Constraints:

   - `1 <= m == grid.length <= 1000`
   - `1 <= n == grid[i].length <= 1000`
   - `m * n <= 1000`
   - `0 <= grid[i][j] <= 1023`
*/

#include <vector>
// Solution0：我拿到这道题最开始的想法，贪心 + 双重循环，首先这道题贪心是错的，很容易找出反例，其次这道题用双循环本身就有很严重的逻辑碰撞，我的实现又漏洞百出
class Solution0 {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i = 0, j = 0;
        int res = grid[i][j];

        while (i + 1 <= m - 1) {
            while (j + 1 <= n - 1) {
                int temp1 = res ^ grid[i + 1][j];
                int temp2 = res ^ grid[i][j + 1];

                if (temp1 < temp2) {
                    res = temp1;
                    ++i; // 绝大部分情况下（几乎是全部）不要在内层循环修改外层循环的控制变量，这样是不规范的，且会造成逻辑混乱
                } else {
                    res = temp2;
                    ++j;
                }

                if (j == n) break;
            }
        }

        // 补丁
        if (i == m - 1 && j != n - 1) {
            while (j < n - 1) {
                res ^= grid[i][++j];
            }
        } else {
            while (i < m - 1) {
                res ^= grid[++i][j];
            }
        }

        return res;
    }
};

// Solution1：这是修改后的实现，依然采用贪心思想，是不对的
class Solution1 {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = grid[0][0];
        int i = 0, j = 0;

        while (i < m - 1 || j < n - 1) {
            if (j == n - 1) res ^= grid[++i][j];
            else if (i == m - 1) res ^= grid[i][++j];
            else {
                int temp1 = res ^ grid[i + 1][j];
                int temp2 = res ^ grid[i][j + 1];

                if (temp1 < temp2) {
                    res = temp1;
                    ++i;
                } else {
                    res = temp2;
                    ++j;
                }
            }
        }

        return res;
    }
};

// Solution2：标准写法，动态规划/BFS集合维护状态

// Solution3：DP优化
