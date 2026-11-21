// LC35.Search Insert Position

/*
   Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

   You must write an algorithm with `O(log n)` runtime complexity.

   Example1:
   Input: nums = [1, 3, 5, 6], target = 5
   Output: 2

   Example2:
   Input: nums = [1, 3, 5, 6], target = 2
   Output: 1

   Example3:
   Input: nums = [1, 3, 5, 6], target = 7
   Output: 4
*/

#include <vector>
#include <algorithm>

class Solution
{
public:
	int searchInsert(std::vector<int>& nums, int target)
	{
        int begin = 0;
        int end = nums.size();
        while (begin < end) {
            int mid = begin + (end - begin) / 2; // 这种写法是为了防止当数据量很大时，begin + end 出现溢出的情况
            // int mid = (begin + end) / 2; // 这会先计算begin + end
            // int mid = end / 2 + begin / 2; // 而end / 2 + begin / 2 这种写法则会面临着小数精度丢失的问题，比如 begin = 3, end = 5. end / 2 + begin / 2 == 3
            if (target > nums[mid]) begin = mid + 1; // +1为了保证每次二分范围严格缩小，否则当出现[0, 1），这种情况时，计算之后还是[0, 1)，进入死循环
            else end = mid;
        }
        return begin;
	}
};

//also
class Solution_
{
public:
	int searchInsert(std::vector<int>& nums, int target)
	{
		return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	}

};
