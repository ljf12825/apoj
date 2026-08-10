// LC27.RemoveElements

/*
原地移除nums中不等于val的元素，返回nums中不等于val的元素的数量
*/

#include <iostream>
#include <vector>

class Solution
{
public:
	int removeElement(std::vector<int>& nums, int val)
	{
		if (nums.empty()) return 0;
		
		int slow = 0;
		for (int fast = 0; fast < nums.size(); ++fast)
			if (nums[fast] != val) nums[slow++] = nums[fast];

		return slow;
	}
};

//erase-remove
class Solution_
{
public:
	int removeElement(std::vector<int>& nums, int val)
	{
		nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
		return nums.size();
	}
};
