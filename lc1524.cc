// LC1524. Number of Sub-array With Odd Sum

/*
   Given an array of integers `arr`, return the number of subarrays with an odd sum.

   Since the answer can be very large, return it modulo `10^9 + 7`.
*/

/*
   Example1:\
   Input: arr = [1,3,5]\
   Output: 4

   Example2:\
   Input: arr = [2,4,6]\
   Output: 0

   Example3:\
   Input: arr = [1,2,3,4,5,6,7]\
   Output: 16
*/

/*
   Constraints:

   - `1 <= arr.length <= 10^5`
   - `1 <= arr[i] <= 100`
*/

#include <vector>
// Solution0：双指针暴力求解，时间复杂度O(n^2)，这是拿到这道题的最开始的思路；遇到数据量很大的用例会TLE，但是它提供了很关键的思路，是优化的开端
class Solution0 {
public:
    int numOfSubarrays(std::vector<int>& arr) {
        int n = arr.size();
        int res = 0;

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += arr[j];
                if (sum % 2 == 1) ++res; // 结果只与奇偶性有关
            }
        }

        return res;
    }
};

// Solution1：前缀和，子数组和是奇数 <=> 子数组内奇数个数为奇数 <=> 前缀和[j] - 前缀和[i-1]为奇数 <=> 两个前缀和奇偶性不同
class Solution1 {
public:
    int numOfSubarrays(std::vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long oddCnt = 0;
        long long evenCnt = 1;
        int prefix = 0;
        long long res = 0;

        for (int x : arr) {
            prefix = (prefix + x) % 2;
            if (prefix == 1) {
                res = (res + oddCnt) % MOD;
                oddCnt++;
            } else {
                res = (res + oddCnt) % MOD;
                evenCnt++;
            }
        }

        return res;
    }
};
