// LC66.AddOne

/*
用一个vector<int>表示一个十进制非负整数
输入vector<int>
输出末位+1后的新数组
*/

#include <vector>
class Solution
{
public:
	std::vector<int>addOne(std::vector<int>& digits)
	{
		for (auto it = digits.rbegin(); it != digits.rend(); ++it)
		{
			if (*it < 9)
			{
				(*it)++;
				return digits;
			}
			*it = 0;
		}
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

class Solution_Recursion
{
private:
	bool plusOneRecursive(std::vector<int>& digits, int index)
	{
		if (index < 0) return true;

		if (digits[index] < 9)
		{
			digits[index]++;
			return false;
		}
		else
		{
			digits[index] = 0;
			return plusOneRecursive(digits, index - 1);
		}
	}

public:
	std::vector<int> plusOne(std::vector<int>& digits)
	{
		if (plusOneRecursive(digits, digits.size() - 1)) digits.insert(digits.begin(), 1);

		return digits;
	}
};
