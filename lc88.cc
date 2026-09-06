// LC88. Merge Sorted Array

/*
   You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively

   Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

   The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`
*/

/*
   Example 1:
   Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
   Output: [1,2,2,3,5,6]

   Example 2:
   Input: nums1 = [1], m = 1, nums2 = [], n = 0
   Output: [1]

   Example 3:
   Input: nums1 = [0], m = 0, nums2 = [1], n = 1
   Output: [1]
*/

#include <vector>

// Solution1 从左往右处理，前插入后删除
class Solution1 {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int> nums2, int n) {
        int i = 0;
        int j = 0;
        if (m == 0) {
            nums1 = nums2;
            return;
        }

        while (i < m + n && j < n) {
            if (nums1[i] <= nums2[j]) ++i;
            else {
                nums1.insert(nums1.begin() + i, nums2[j]);
                nums1.pop_back();
                ++i;
                ++j;
            }
        }

        if (j != n) {
            i = i - n + j;
            for (; j < n; ++j) {
                nums1[i++] = nums2[j];
            }
        }
    }
};

// Solution2 从右往左写
// 当从左往右解决一个问题很复杂的时候，不想想能不能从右往左
class Solution2 {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int> nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && k >= 0)
            // 两个vector从右到左挑最大的写到nums1的最后（相对）
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

        if (i < 0 && j >= 0) { // 当nums1的元素位置全部确定了，但nums2还有剩余，说明nums2的剩余元素比nums1的小，k继续往前走，把nums2中的元素充填进去
            for (; k >= 0; --k) {
                nums1[k] = nums2[j--];
            }
        }
    }
};
