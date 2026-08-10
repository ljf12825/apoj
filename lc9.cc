// LC9 IsPalindrome

/*
回文数
判断一个数是否是回文数

边界情况
负数、结尾是0且不等于0的数不是回文数
*/

#include <iostream>

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0 || (x % 10 == 0 && x != 0)) return false;

		int reversedNumber = 0;

		while (x > reversedNumber)
		{
			reversedNumber = reversedNumber * 10 + x % 10;
			x /= 10;
		}

		return x == reversedNumber || x == reversedNumber / 10;
	}
};
