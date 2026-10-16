// LC2916. Subarrays Distinct Element Sum of Squares II

/*
   You are given a 0-indexed integer array `nums`.

   The distinct count of a subarray of `nums` is defined as:

   - Let `nums[i..j]` be a subarray of `nums` consisting of all the indices from `i` to `j` such that `0 <= i <= j < nums.length`. Then the number of distinct value in `nums[i..j]` is called the distinct count of `nums[i..j]`.

   Return the summary of the squares of distinct counts of all subarray of `nums`.

   Since the answer may be very large, return it modulo `10^9 + 7`

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
   Input: nums = [2,2]\
   Output: 3
*/

/*
   Constraints:\
   - `1 <= nums.length <= 10^5`
   - `1 <= nums[i] <= 10^5`
*/

#include <unordered_map>
#include <vector>
// 本题是LC2913的完整形态，数据范围和大小已经不适合使用双重循环暴力枚举了
// Solution1 线段树
class Solution1 {
    static constexpr long long MOD = 1'000'000'007;
    std::vector<long long> sum1, sum2, lazy;
    std::vector<int> len;
    int n;

    void build(int node, int l, int r) {
        len[node] = r - l + 1;
        sum1[node] = sum2[node] = lazy[node] = 0;
        if (l == r) return;
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
    }

    void apply(int node, long long v) {
        long long L = len[node];
        sum2[node] = (sum2[node] + 2 * v % MOD * sum1[node] % MOD + v * v % MOD * L % MOD) % MOD;
        sum1[node] = (sum1[node] + v * L % MOD) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }

    void pushDown(int node) {
        if (lazy[node] == 0) return;
        apply(node * 2, lazy[node]);
        apply(node * 2 + 1, lazy[node]);
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr, long long v) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) { apply(node, v); return; }
        pushDown(node);
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, v);
        update(node * 2 + 1, mid + 1, r, ql, qr, v);
        sum1[node] = (sum1[node * 2] + sum1[node * 2 + 1]) % MOD;
        sum2[node] = (sum2[node * 2] + sum2[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(std::vector<int>& nums) {
        n = nums.size();
        int N = 4 * n + 5;
        sum1.assign(N, 0);
        sum2.assign(N, 0);
        lazy.assign(N, 0);
        len.assign(N, 0);
        build(1, 0, n - 1);

        long long ans = 0;
        std::unordered_map<int, int> last;

        for (int j = 0; j < n; ++j) {
            int prev = last.count(nums[j]) ? last[nums[j]] : -1;
            update(1, 0, n - 1, prev + 1, j, 1);
            last[nums[j]] = j;
            ans = (ans + sum2[1]) % MOD;
        }

        return (int)ans;
    }
};
