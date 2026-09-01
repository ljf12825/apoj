// LC66. Plus One

/*
   You are given a large integer represented as an integer array `digits`, where each `digits[i]` is the `ith` digit of the intteger.\
   The digits are ordered from most significant to least significant in left-to-right order. The large integer dose not contain any leading `0`'s.

   Increment the large integer by on and return the resulting array of digits.

   Example1:
   Input: digits = [1, 2, 3]
   Output: [1, 2, 4]
   Explanation: The array represents the integer 123.\
   Incrementing by one give 123 + 1 = 124.\
   Thus, the result should be [1, 2, 4]

   Example2:
   Input: digits = [9]
   Output: [1, 0]
   Explanation: The array represents the integer 9.\
   Incrementing by one gives 9 + 1 = 10.\
   Thus, the result should be [1, 0]
*/

#include <vector>
class Solution
{
public:
	std::vector<int>plusOne(std::vector<int>& digits)
	{
		for (auto it = digits.rbegin(); it != digits.rend(); ++it)
		{
			if (*it < 9) // 只要遇到不是9的数，该位置加1就能结束问题
			{
				(*it)++;
				return digits;
			}
			*it = 0;
		}
		digits.insert(digits.begin(), 1); // 循环完毕说明首位是0，首位insert 1
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
