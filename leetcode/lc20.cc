// LC20.Valid Parentheses

/*
   Given a string `s` containing just the characters `(`, `)`, `{`, `}`, `[` and `]`, determain if the input string is valid\

   An input string is valid if:

   1. Open backets must be closed by the same type of brackets.
   2. Open backets must be closed in the correct order.
   3. Every close bracket has a corresponding open bracket of the same type.

   Example 1:\
   Input: s = "()"
   Output: true

   Example 2:\
   Input: s = "()[]{}"\
   Output: true

   Example 3:\
   Input: s = '(]'\
   Output: false

   Example 4:\
   Input: s = "([])"\
   Output: true

   Example 5:\
   Input: s = "([)]"\
   Output: false
*/

#include <stack>
#include <unordered_map>
#include <string>

class Solution
{
public:
	bool isValid(std::string s)
	{
		if (s.size() % 2 != 0) return false;
		std::unordered_map<char, char> table =
		{
			{')', '('}, {']', '['}, {'}', '{'}
		};

		std::stack<char> stk;
		for (char ch : s)
		{
			if (table.count(ch))
			{
				if (stk.empty() || stk.top() != table[ch]) return false;
				stk.pop();
			}
			else stk.push(ch);
		}
		return stk.empty();
	}

};
