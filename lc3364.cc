// LC3364. Minimum Positive Sum Subarray

/*
   You are given an integer array `nums` and two integers `l` and `r`. Your task is to find the minimum sum of a subarray whose size is between `l` and `r`(inclusive) and whose sum is greater than 0.

   Return the minimum sum of such a subarray. If no such subarray exists, return -1.

   A subarray is a contiguous non-empty sequence of elements within an array.
*/

/*
   Example1:\
   Input: nums = [3,-2,1,4], l = 2, r = 3\
   Output: 1

   Example2:\
   Input: nums = [-2,2,-3,1], l = 2, r = 3\
   Output: -1

   Example3:\
   Input: nums = [1,2,3,4], l = 2, r = 4\
   Output: 3
*/

/*
   Constraints:

   - `1 <= nums.length <= 100`
   - `1 <= l <= r <= nums.length`
   - `-1000 <= nums[i] <= 1000`
*/

#include <algorithm>
#include <climits>
#include <iterator>
#include <set>
#include <vector>
// Solution1：三重循环暴力求解，直接根据题意写，因为Constraints数据规模较小，所以这道题可以这样写
class Solution1 {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int minres = INT_MAX;
        int n = nums.size();

        for (int i = l; i <= r; ++i) {
            for (int j = 0; j + i <= n; ++j) {
                int res = 0;
                for (int k = 0; k < i; ++k) res += nums[j + k];

                if (res > 0) minres = std::min(minres, res);
            }
        }

        if (minres == INT_MAX) return -1;
        else return minres;
    }
};

// Solution2：双重循环优化，固定一端，移动另一端，这样能直接复用上一步的计算结果，不会打断连续状态。时间复杂度O(n^2)，空间复杂度O(1)
class Solution2 {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int minres = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = i; j < n && j - i + 1 <= r; ++j) {
                res += nums[j];

                if (j - i + 1 >= l && res> 0) minres = std::min(minres, res);
            }

        }

        return minres == INT_MAX ? -1 : minres;
    }
};

// Solution3：复杂度最优解，前缀和 + `multiset`，时间复杂度O(n log n)，空间复杂度O(n)。当数据规模扩大到10^5时，上面的两种写法就会TLE
class Solution3 {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int n = nums.size();
        std::vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + nums[i];

        int ans = INT_MAX;
        std::multiset<int> window;

        for (int j = l; j <= n; ++j) {
            window.insert(pre[j - l]);

            auto it = window.lower_bound(pre[j]);
            if (it != window.begin()) ans = std::min(ans, pre[j] - *std::prev(it));

            if (j >= r) window.erase(window.find(pre[j - r]));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
