// LC1267. count Servers that Communicate

/*
   You are given a map of a server center, represented as a `m * n` integer matrix `grid`, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

   Return the number of servers that communicate with any other server.
*/

/*
   Example1:\
   Input: grid = [[1,0], [0,1]]\
   Output: 0

   Example2:\
   Input: grid = [[1,0], [1,1]]\
   Output: 3

   Example3:\
   Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,1],[0,0,0,1]]\
   Output: 4
*/

/*
   Constraints:

   - `m == grid.length`
   - `n == grid[i].length`
   - `1 <= m <= 250`
   - `1 <= n <= 250`
   - `grid[i][j] == 0 or 1`
*/

#include <vector>
// Solution1：收集每行每列情况，再逐个判断
class Solution1 {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<int> row(m, 0), col(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++row[i];
                    ++col[j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) ++ans;
            }
        }

        return ans;
    }
};
