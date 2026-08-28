// LC27.RemoveElements

/*
   Given an integer array `nums` an integer `val`, remove all occurrences of `val` in `nums` in-place. The order of the elements may be changed. Then return the number of elements in `nums` which are not equal to `val`

   Consider the number of elements in `nums` which are not equal to `val` be `k`, to get accepted, you need to do the following things:

   - Change the array `nums` such that the first `k` elements of `nums` contain the elements which are not equal to `val`. The remaining elements of `nums` are not important as well as the size of `nums`
   - Return `k`

   Custom Judge:\
   The judge will test your solution with the following code:

   ```
    int[] nums = [...]; // Input array
    int val = ...; // Value to remove
    int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

    int k = removeElement(nums, val); // Calls your implementation

    assert k == expectedNums.length;
    sort(nums, 0, k); // Sort the first k elements of nums
    for (int i = 0; i < actualLength; i++) {
        assert nums[i] == expectedNums[i];
    }
   ```
If all assertions pass, then your solution will be accepted

Example 1:
    Input: nums = [3, 2, 2, 3], val = 3
    Output: 2, nums = [2, 2, _, _]
    Explanation: Your function should return k = 2, with the first two elements of nums being 2.
    It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
    Input: nums = [0, 1, 2. 2. 3. 0, 4, 2], val = 2
    Output: 5, nums = [0, 1, 4, 0, 3, _, _, _]
    Explanation: Your function should return k = 5, with the first five elements of nums contain 0, 0, 1, 3 and 4.
    Note that the five elements can be returned in any order.
    It does not matter what you leave beyond the returned k (hence they are underscores)
*/

#include <vector>
#include <algorithm>

// 快慢指针
class Solution1
{
public:
	int removeElement(std::vector<int>& nums, int val)
	{
		if (nums.empty()) return 0;
		
		int slow = 0;
		for (int fast = 0; fast < nums.size(); ++fast)
			if (nums[fast] != val) nums[slow++] = nums[fast]; // 不用考虑任何事情，fast指针在前面探路，过滤掉val值，slow只需要逐位重写就可以了，并且题目中说不用考虑vector的后部

		return slow; // slow 的初始值为0， 最后一次循环往前走一位，正好等于要求元素的数量
	}
};

//erase-remove
class Solution2
{
public:
	int removeElement(std::vector<int>& nums, int val)
	{
		nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
		return nums.size();
	}
};

// std::vector::erase()
/* 这个算法的时间复杂度是O(n^2)\
   但是因为LeetCode的数据规模很小

   - `0 <= nums.length <= 100`
   - `0 <= nums[i] <= 50`
   - `0 <= val <= 100`
   所以在该场景下性能与双指针相差无几
*/
class Solution3 {
public:
    int removeElement(std::vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                --i; // erase会让后方元素补位，所以需要重新判断当前位置
            }
        }

        return nums.size();
    }
};
