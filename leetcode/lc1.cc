// LC1.Two Sum

/*
You are given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly on solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2, 7, 11, 15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] = 9
*/

#include <vector>
#include <unordered_map>

//1.暴力求解
//O(n^2)
class Solution1
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < nums.size(); ++j)
				if (nums[i] + nums[j] == target) return { i, j }; // 这相当于在vector里线性搜索结果O(n)
		}
		return {};
	}
};

//2.哈希表
//O(n)
class Solution2
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		std::unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i)
		{
			auto it = hashtable.find(target - nums[i]); // 使用哈希表查询时间复杂度为O(1)
			if (it != hashtable.end()) return { it->second, i };
			hashtable[nums[i]] = i; // 在一个循环里同时维护一个哈希表，一遍走过不会重复
		}
		return {};
	}
};

/*
这道题的核心就是把O(n)的线性查找换成平均O(1)的哈希查找
还有就是在线处理：维护已经处理过的数据，同时用它解决当前问题
我一开始想到的也是做差，但是想到是不是还要在vector里搜索，内层的时间复杂度还是O(n)，没想到用哈希表
*/
