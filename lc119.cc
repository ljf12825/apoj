// LC119. Pascal's Triangle II

/*
   Given an integer `rowIndex`, return the `rowIndex^th`(0-indexed) row of the Pascal's triangle.

   In Pascal's triangle, each number is the sum of the two numbers directly above it as shown
*/

/*
   Example1:\
   Input: rowIndex = 3\
   Output: [1,3,3,1]

   Example2:\
   Input: rowIndex = 0\
   Output: [1]

   Example3:\
   Input: rowIndex = 1\
   Output: [1,1]
*/

#include <vector>
// Solution1：递归实现
class Solution1 {
public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return { 1 };
        if (rowIndex == 1) return { 1, 1 };
        else {
            std::vector<int> prevec = getRow(rowIndex - 1);
            std::vector<int> tempvec; // 这里会保留所有行的结果，导致空间复杂度为O(n^2)
            int i = 0;
            int j = 1;
            tempvec.push_back(1);
            while (j < prevec.size()) {
                tempvec.push_back(prevec[i] + prevec[j]);
                ++i;
                ++j;
            }
            tempvec.push_back(1);

            return tempvec;
        }
    }
};

// Solution2：迭代
class Solution2 {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 1);

        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                row[j] += row[j - 1]; // 直接在row里修改，自始至终只有一个row
            }
        }

        return row;
    }
};
