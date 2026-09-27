// LC118. Pascal's Triangle

/*
   Given an integer `numRows`, return the first numRows of Pascal's triangle.

   In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

       1
      1 1
     1 2 1
    1 3 3 1
   1 4 6 4 1

*/

/*
   Example1:\
   Input: numRows = 5\
   Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

   Example2:\
   Input: numRows = 1\
   Output: [[1]]
*/

#include <vector>
// Solution1：动态规划递归实现；转移方程为dp[i][j] == dp[i - 1][j - 1] + dp[i - 1][j]
class Solution1 {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows == 0) return basevec;
        else if (numRows == 1) {
            std::vector<int> vec;
            vec.push_back(1);
            basevec.push_back(vec);
        } else if (numRows == 2) {
            generate(--numRows);
            std::vector<int> vec;
            vec.push_back(1);
            vec.push_back(1);
            basevec.push_back(vec);
        } else {
            int i = 0;
            int j = 0;
            std::vector<std::vector<int>> prevec = generate(--numRows); // 上一行
            std::vector<int> tempvec;
            tempvec.push_back(1);
            while (j < prevec[numRows - 1].size()) { // 上一行在prevec中的索引
                tempvec.push_back(prevec[numRows - 1][i] + prevec[numRows - 1][j]);
                ++i;
                ++j;
            }
            tempvec.push_back(1);
            basevec.push_back(tempvec);
        }
        return basevec;
    }

private:
    std::vector<std::vector<int>> basevec;
};

// Solution2：动态规划迭代实现
class Solution2 {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;

        for (int i = 0; i < numRows; ++i) {
            std::vector<int> row(i + 1, 1);

            for (int j = 1; j < 1; ++j) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }

            result.push_back(row);
        }

        return result;
    }
};
