// LC58.LengthofLastWord

/*
字符串s由若干个单词和空格组成
求最后一个单词的长度
单词是指仅由字母组成、不包含任何空格字符的最大子字符串
*/

#include <iostream>
#include <string>

class Solution
{
public:
	int lenthOfLastWord(std::string s)
	{
		int n = 0;
		for (auto index = s.rbegin(); index != s.rend(); ++index)
		{
			if (*index != ' ') ++n;
			else if (n > 0) break;
		}
		return n;
	}
};
