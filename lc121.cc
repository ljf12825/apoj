// LC121. Best Time to Buy and Sell Stock

/*
   You are given an array `prices` where `prices[i]` is the price of a given stock on the `i^th` day.

   You want to maximize your profit by choosing a single day to buy on stock and choosing a different day in the future to sell that stock.

   Return the maximium profit you can achieve from this transaction. If you cannot achieve any profit, return `0`
*/

/*
   Example1:\
   Input: prices = [7,1,5,3,6,4]\
   Output: 5\
   Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5\
   Note that buying on day 2 and selling on day is not allowed because you must buy before you sell.

   Example2:\
   Input: prices = [7,6,4,3,1]\
   Output: 0\
   Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include <algorithm>
#include <set>
#include <vector>
//Solution0：暴力求解，我的解法，198/213 testcases passed 总体时间复杂度为O(n^2 log n)，这对于某些数据量很大，针对暴力解法的用例来说会超时
class Solution0 {
public:
    int maxProfit(std::vector<int>& prices) {
        int i = 0;
        std::set<int> table;
        while (i < prices.size() - 1) { // 外层 O(n)
            int j = i + 1;
            while (j < prices.size()) { // 内层 O(n)
                table.insert(prices[j] - prices[i]); // std::set.insert() O(log n)
                ++j;
            }
            ++i;
        }
        if (table.empty()) return 0;
        return *table.rbegin() > 0 ? *table.rbegin() : 0;
    }
};

// Solution1：仅维护minPrice和maxProfit
class Solution1 {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = std::min(price, minPrice);
            maxProfit = std::max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
