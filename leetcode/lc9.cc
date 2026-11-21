// LC9 Palindrome Number

/*
Given an interget `x`, return `true` if `x` is a palindrome, and `false` otherwise

Example:
Input: x = 121
Output: true
*/

// 存起来首尾逐个比较

#include <vector>
class Solution1 {
public:
    bool isPalidrome(int x) {
        if (x < 0) return false;

        std::vector<int> vec;
        do {
            vec.push_back(x % 10); // 空间复杂度O(n)
            x /= 10;
        }while (x != 0);

        while (vec.size() > 1 && vec.front() == vec.back()) { // 每次循环问题规模 -2；所以外侧时间复杂度为O(n);
            vec.pop_back();
            vec.erase(vec.begin()); // erase是时间复杂度O(n)的操作，每次删除后一个元素后都需要把后方元素往前移动
        } // 所以整体时间复杂度是O(n^2)

        return vec.empty() || vec.size() == 1;
    }
};

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0 || (x % 10 == 0 && x != 0)) return false; // 负数，末尾是零的数都不是回文数，0是回文数

		int reversedNumber = 0;

		while (x > reversedNumber)
		{
			reversedNumber = reversedNumber * 10 + x % 10;
			x /= 10;
		} // O(log n) n 定义为x的值

		return x == reversedNumber || x == reversedNumber / 10;
	}
};
