// LC3963. Create Grid With Exactly One Path

/*
   You are given two integers `m` and `n`, representing the number of rows and columns of a grid.

   Construct any `m * n` grid consisting onlly of the characters `'.'` and `'#'`, where:

   - `'.'` represents a free cell.
   - `'#'` represents an obstacle cell.

   A valid path is a sequence of free cells that:

   - Starts at the top-left cell `(0, 0)`.
   - Ends at the bottom-right cell `(m - 1, n - 1)`.
   - Moves only:
     - Right, from `(i, j)` to `(i, j + 1)`, or
     - Down, from `(i, j)` to `(i + 1, j)`.

     Return any grid such that there is exactly one valid path from the top-left cell to the bottom-right cell.
*/

/*
   Example1:\
   Input: m = 2, n = 3\
   Output: ["..#", "#.."]\
   Explanation:

   -------------
   | . | . | # |
   -------------
   | # | . | . |
   -------------

   The only valid path is: `(0,0) -> (0,1) -> (1,1) -> (1,2)`

   Example2:\
   Input: m = 3, n = 3\
   Output: ["..#", "#..", "##."]

   Example3:\
   Input: m = 1, n = 4\
   Output: ["...."]
*/

/*
   Constraints:

   - `1 <= m, n <= 25`
*/

#include <string>
#include <vector>
// Solution1: 我的解法，几行几列，固定第一行一直向右，最后一列一直向下，双循环，时间复杂度O(m * n)
class Solution1 {
public:
    std::vector<std::string> createGrid(int m, int n) {
        std::vector<std::string> vec;

        for (int i = 0; i < m; ++i) {
            std::string row;
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == n - 1) row.push_back('.');
                else row.push_back('#');
            }

            vec.push_back(row);
        }

        return vec;
    }
};

// Solution2：优化写法，定量初始化并在两个并列的循环中修改
class Solution2 {
public:
    std::vector<std::string> createGrid(int m, int n) {
        std::vector<std::string> vec(m, std::string(n, '#')); // 定量初始化，避免反复扩容

        for (int j = 0; j < n; ++j) vec[0][j] = '.';

        for (int i = 0; i < m; ++i) vec[i][n - 1] = '.';

        return vec;
    }
};
