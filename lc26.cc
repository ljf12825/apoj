// LC26. Remove Duplicates from Sorted Array

/*
   Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same

   Consider the number of unique elements in `nums` to be `k`. After removing duplicates, return the number of unique elements `k`.

   The first `k` elements of `nums` should contain the unique numbers in sorted order. The remaining elements beyond index `k-1` can be ignored

   Custom Judge:\
   The judge will test your solution with the following code:

   ```
    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct length

    int k = removeDuplicate(nums); // Call your implementation

    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }
   ```

   Example 1:
   Input: nums = [1, 1, 2]
   Output: 2, nums = [1, 2, _]
   Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.\
   It does not matter what you leave beyond the return k (hence they are underscores).
*/

#include <vector>
#include <algorithm>

// 真清理
class Solution1 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;
        if (nums.size() == 0) return nums.size();

        while (i < nums.size() - 1) {
            if (nums[i] == nums[i + 1]) nums.erase(nums.begin() + i + 1); // erase的时间复杂度是O(n)，因为要移动后方元素填补空缺
            else ++i;
        }
        return nums.size();
    }
};

// 试图构造新的vector以取代std::vector::erase的O(n) 时间复杂度
class Solution2 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 0) return nums.size();
        int i = 0;
        int j = 1;
        std::vector<int> temp;

        while (i < nums.size()) {
            if (j >= nums.size()) {
                temp.push_back(nums[i]);
                break;
            }
            if (nums[i] <= nums[j]) ++j;
            else {
                temp.push_back(nums[i]); // 但是空间复杂度为O(n)
                i = j;
                ++j;
            }
        }
        nums = temp;
        return nums.size();
    }
};

// 直接写原vector
class Solution3
{
public:
	int removeDuplicates(std::vector<int>& nums)
	{
		if (nums.empty()) return 0;
		int slow = 0;
		for (int fast = 0; fast < nums.size(); ++fast)
			if (nums[fast] != nums[slow]) nums[++slow] = nums[fast];

		return slow + 1;
	}
};

// 用标准库API erase-unique
class Solution4
{
public:
	int removeDuplicates(std::vector<int>& nums)
	{
		nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

		return nums.size();
	}
};
