// LC15. 3Sum

/*
   Given an integer array nums. return all the triplets `nums[i], nums[j], nums[k]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`

   Notice that the solution set must not contain duplicate triplets.
*/

/*
   Example1:\
   Input: nums = [-1, 0 ,1, 2, -1, -4]\
   Output: [[-1, -1, 2], [-1, 0, 1]]\
   Explanation:\
   nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.\
   nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.\
   nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0\
   The distinct triplets are [-1, 0, 1] and [-1, -1 ,2]\

   Example2:\
   Input: nums = [0,1,1]\
   Output: []\

   Example3:\
   Input: nums = [0,0,0]\
   Output: [[0,0,0]]
*/

#include <algorithm>
#include <unordered_set>
#include <vector>

// Solution0：三重循环暴力求解，这个方法最直观，但通常超时而且需要去重，这是思考的起点，但并不是最终解法。a + b + c = 0，c = -(a + b)三数之和其实是两数之和，因为任意两个数字确定，第三个数字一定唯一。假设固定a = -1，再选定b = 0，那么c = -(-1 + 0) = 1，然后就是找c。

// Solution1：排序 + 双指针
class Solution1 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) ++ left;
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
                } else if (sum < target) ++left;
                else --right;
            }
        }

        return result;
    }
};

// Solution2：哈希表法
class Solution2 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            std::unordered_set<int> seen;
            std::unordered_set<int> used;

            for (int j = i + 1; j < n; ++j) {
                int target = -nums[i] - nums[j];

                if (seen.count(target)) {
                    if (used.insert(target).second) res.push_back({nums[i], target, nums[j]});
                }

                seen.insert(nums[j]);
            }
        }

        return res;
    }
};

// Solution3：排序 + 二分查找
class Solution3 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 1; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int target = -nums[i] - nums[j];

                auto it = std::lower_bound(nums.begin() + j + 1, nums.end(), target);

                if (it != nums.end() && *it == target) res.push_back({nums[i], nums[j], target});
            }
        }

        return res;
    }
};
