// LC11. Container With Most Water

/*
    You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i^th` line are `(i, 0)` and `(i, height[1])`.

    Find two lines that together with the x-axis form a container, such that the container contains the most water.

    Return the maximum amount of water a container can store

    Notice that you may not slant the container.
*/

/*
    Example1:\
    Input: height = [1,8,6,2,5,4,8,3,7]\
    Output: 49

    Example2:\
    Input: height = [1,1]\
    Output: 1
*/

#include <algorithm>
#include <vector>

// Solution1 双循环暴力求解，理论上是好的，但是leetcode的部分测试用例数据量很大会超时
class Solution1 {
public:
    int maxArea(std::vector<int>& height) {
        int i = 0;
        int j = 1;
        int result = 0;

        while (i < j && j < height.size()) {
            while (j < height.size()) {
                int h = height[i] < height[j] ? height[i] : height[j];
                int temp = h * (j - i);
                result = result > temp ? result : temp;
                ++j;
            }

            j = ++i + 1;
        }

        return result;
    }
};

// Solution2 双指针消除无效状态优化
class Solution2 {
public:
    int maxArea(std::vector<int>& height) {
        int i = 0, j = height.size() - 1, result = 0;

        while (i < j) {
            result = std::max(result, std::min(height[i], height[j]) * (j - 1));
            // 能接到的最多的水取决于最低高度
            // 假设当前i, j作为起点，固定i，把j从右往左移动，那么宽度(j - i)一定会变小，高度min(height[i], height[j])，最大height[i]，此时面积的最大值就是起点的j，所以j的移动产生的其他情况一定不会超过这个值
            // 所以当height[i] < height[j] 时，height[i]的最大情况已经有了，其他情况不用看，i前进；height[i] > height[j]时同理
            // 这样就剪枝掉了暴力求解的部分情况，将O(n^2)通过找到一种单调性，降解为O(n)
            if (height[i] < height[j]) ++i;
            else --j;
        }

        return result;
    }
};