// LC58.Length of Last Word

/*
   Given a string `s` consisting of words and spaces, return the length of the last word in the string

   A word is a maximal substring consisting of non-space characters only

   Example1:
   Input: s = "Hello World!"
   Output: 5
   Explanation: The last word is "World" with length 5.

   Example2:
   Input: s = "  fly me  to  the moon "
   Output: 4;
   Explanation: The last word is "moon" with length 4

   Example3:
   Input: s = "luffy is still joyboy"
   Output: 6
   Explanation: The last word is "joyboy" with length 6
*/

#include <string>

class Solution
{
public:
	int lengthOfLastWord(std::string s)
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
