// LC3551. Minimum Swaps to Sort by Digit Sum

/*
    You are given an array `nums` of distinct positive integers.\
    You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smallr number appears first in the sorted order.

    Return the minimum number of swaps required to rearrange `nums` into this sorted order.

    A swap is defined as exchanging the values at two distinct positions in the array.
*/

/*
    Example1:\
    Input: nums = [37,100]\
    Output: 1\

    Example2:\
    Input: nums = [22, 14, 33, 7]\
    Ouput: 0

    Example3:\
    Input: nums = [18,43,34,16]\
    Output: 2
*/

/*
    Constraints:

    - `1 <= nums.length <= 10^5`
    - `1 <= nums[i] <= 10^9`
    - `nums` consists of distinct positive integers.
*/

// Solution 原数组使用sort自定义排序后，通过置换环求解
#include <algorithm>
#include <array>
#include <vector>
class Solution {
public:
    int minSwap(std::vector<int>& nums) {
        int n = nums.size();

        std::vector<std::array<int, 3>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; ++i) {
            arr.push_back({digitSum(nums[i]), nums[i], i});
        }

        std::sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) return a[0] < b[0];

            return a[1] < b[1];
        });

        std::vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                ++cycleSize;

                j = arr[j][2];
            }

            ans += cycleSize - 1;
        }

        return ans;
    }

private:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }
};