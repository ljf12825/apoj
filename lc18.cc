// LC18. 4Sum

/*
   Given an array `nums` of `n` integers, return an array of all the unique quadruplets `nums[a], nums[b], nums[c], nums[d]` such that:

   - `0 <= a, b, c, d < n`
   - `a`,`b`,`c` and `d` are distinct.
   - `nums[a] + nums[b] + nums[c] + nums[d] == target`

   You may return the answer in any order.
*/

/*
   Example1:\
   Input: nums = [1,0,-1,0,-2,2], target = 0\
   Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

   Example2:\
   Input: nums = [2,2,2,2,2], target = 8;
   Output: [[2,2,2,2]]
*/

/*
   Constraints:\
   - `1 <= nums.length <= 200`
   - `-10^9 <= nums[i] <= 10^9`
   - `-10^9 <= target <= 10^9`
*/

#include <algorithm>
#include <vector>
// 本题和LC15, LC16本质是一样的，排序 + 双指针，只不过多一层。因为数据规模nums.length <= 200，所以三重循环耗时并不高，但是要注意在四个数相加时产生的中间值可能溢出int，可以用long long
// Solution1：无优化
class Solution1 {
public:
    std::vector<std::vector<int>> forSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        if (nums.size() < 4) return res;

        std::sort(nums.begin(), nums.end());
        int len = nums.size(); // nums.size() 是一个size_t类型，直接和int发生算术容易发生问题，所以先转化成int

        for (int i = 0; i < len - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 一次循环代表已经处理完这一位的所有情况，i 层级表示所有nums[i]的情况已经列出，所以如果下一位还是i，直接跳过

            for (int j = i + 1; j < len - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // j 是在固定一个i的情况下的层级，表示在某个i 下所有j的情况已经处理完，遇到相同的j就跳过
                int left = j + 1;
                int right = len - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) { // 1. 保存，2. 去重，3. 移动 步骤不能变
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;

                        ++left;
                        --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }

        return res;
    }
};

// Solution2：提前剪枝部分情况，在LeetCode的本题用例池中收益很高
class Solution2 {
public:
    std::vector<std::vector<int>> forSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        if (nums.size() < 4) return res;

        std::sort(nums.begin(), nums.end());
        int len = nums.size();

        for (int i = 0; i < len - 3; ++i) {
            // 剪枝1：i层minsum > target，直接结束
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // 剪枝2：i层maxsum < target，这个i无解，跳过
            if ((long long)nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) continue;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < len - 2; ++j) {
                // 剪枝3：j层minsum > target，break
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                // 剪枝4：j层maxsum < target，continue
                if ((long long)nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target) continue;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = len - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;

                        ++left;
                        --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }

        return res;
    }
};
