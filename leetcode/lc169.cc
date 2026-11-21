// LC169. Majority Element

/*
   Given an array `nums` of size `n`, return the majority element.

   The majority element is the element that appears more than `[n / 2]` times. You may assume that the majority element always exists in the array.
*/

/*
   Example1:\
   Input: nums = [3,2,3]\
   Output: 3

   Example2:\
   Input: nums = [2,2,1,1,1,2,2]\
   Output: 2
*/

/*
   Constraints:\
   - `n == nums.length`
   - `1 <= n <= 5 * 10^4`
   - `-10^9 <= nums[i] <= 10^9`
   - The input is generated such that a majority element will exist in the array.
*/

/*
   Follow-up: Could you solve the problem in linear time and in `O(1)` space?
*/

#include <algorithm>
#include <unordered_map>
#include <vector>
// Solution1：额外k-v结构统计
class Solution1 {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;
        int res = std::max_element(mp.begin(), mp.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->first;

        return res;
    }
};

// Solution2：Boyer_moore 投票算法，时间复杂度O(n)，空间复杂度O(1)
// 原理：把“多数元素”看作+1，其他看作-1，互相抵消后剩下的就是多数元素。因为多数元素出现次数>n/2，无论怎么抵消，它最终一定剩下来
class Solution2 {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int x : nums) {
            if (count == 0) candidate = x;
            count += (x == candidate) ? 1 : -1;
        }

        // 本题保证多数元素必定存在，也就是有一个数字出现的次数>n/2次。如果不保证必定存在，需要再验证一遍
        int freq = 0;
        for (int x : nums) if (x == candidate) ++freq;

        if (freq > nums.size() / 2) return candidate;

        return -1;
    }
};

// Solution3：排序找中位数，因为多数元素出现次数>n/2，因此排序后相同元素连续排列，一个出现超过一半的元素，无论在哪里，都必然覆盖数组的中位数，极限情况是这个数的最后一个数字或第一个数字在中位数
class Solution3 {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }
};
