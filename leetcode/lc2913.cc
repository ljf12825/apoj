// LC2913. Subarrays Distinct Element Sum of Squares I

/*
   You are given a 0-indexed integer array `nums`.

   The distinct count of a subarray of `nums` is defined as:

   - Let `nums[i..j]` be a subarray of `nums` consisting of all the indices from `i` to `j` such that `0 <= i <= j < nums.length`. Then the number of distinct value in `nums[i..j]` is called the distinct count of `nums[i..j]`.

   Return the summary of the squares of distinct counts of all subarray of `nums`.

   A subarray is a contiguous non-empty sequence of elements within an array.
*/

/*
   Example1:\
   Input: nums = [1,2,1]\
   Output: 15\
   Explanation: Six possible subarrays are:\
   [1]: 1 distinct value\
   [2]: 1 distinct value\
   [1]: 1 distinct value\
   [1,2]: 2 distinct values\
   [2,1]: 2 distinct values\
   [1,2,1]: 2 distinct values\
   The sum of the squares of the distinct counts in all subarray is equal to 1^2 + 1^2 + 1^2 + 1^2 + 2^2 + 2^2 = 15

   Example2:\
   Input: nums = [1,1]\
   Output: 3
*/

/*
   Constraints:\
   - `1 <= nums.length <= 100`
   - `1 <= nums[i] <= 100`
*/

#include <set>
#include <unordered_set>
#include <vector>
// Solution1：我的解法，拆分，去重，统计；时间复杂度O(n^3 log n)，空间复杂度O(n^2)，这题数据规模很小，能通过
class Solution1 {
public:
    int sumCounts(std::vector<int>& nums) {
        int sum = 0;
        int numslength = 1;
        while (numslength <= nums.size()) {
            std::vector<std::vector<int>> subarray = subarrayres(nums, numslength);

            for (int i = 0; i < subarray.size(); ++i) {
                sum += singlecount(subarray[i]) * singlecount(subarray[i]);
            }

            numslength++;
        }

        return sum;
    }

    std::vector<std::vector<int>> subarrayres(std::vector<int>& nums, int length) {
        std::vector<std::vector<int>> table;
        int index = 0;
        while (index + length <= nums.size()) {
            std::vector<int> temp;
            for (int i = 0; i < length; ++i) {
                temp.push_back(nums[index + i]);
            }

            ++index;
            table.push_back(temp);
        }

        return table;
    }

    int singlecount(std::vector<int>& nums) {
        std::set<int> table;
        for (int i = 0; i < nums.size(); ++i) {
            table.insert(nums[i]);
        }

        return table.size();
    }
};

// Solution2：换种思考方式，从按子集规模变成按位，每一位会存在的子数组的结果累加，然后逐位前进
class Solution2 {
public:
    int sumCounts(std::vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            std::unordered_set<int> table;
            for (int j = i; j < nums.size(); ++j) {
                table.insert(nums[j]);
                int d = table.size();
                sum += d * d;
            }
        }

        return sum;
    }
};
