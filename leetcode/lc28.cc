// LC28.Find the Index of the First Occurrence in a String

/*
   Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`

   Example1:
   Input: haystack = "sadbutsad", needle = "sad"
   Output: 0
   Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0, so we return 0.

   Example2:
   Input: haystack = "leetcode", needle = "leeto"
   Output: -1
   '
*/

#include <string>
#include <vector>

//方法1
class Solution_1
{
public:
	int strStr(std::string haystack, std::string needle)
	{
		for (int i = 0; i + needle.size() < haystack.size(); ++i)
		{
			bool flag = true;
			for (int j = 0; j < needle.size(); ++j)
			{
				if (haystack[i + j] != needle[j]) // 不要试图在内层循环里改变循环变量，这是不良写法，会变得不幸
				{
					flag = false;
					break;
				}
			}
			if (flag) return i;
		}
		return -1;
	}
};

//方法2
class Solution_2
{
public:
	int strStr(std::string haystack, std::string needle)
	{
		return haystack.find(needle);
	}
};

//方法3
//KMP(Knuth-Morris-Pratt)算法
//用于在一个文本串中快速查找一个模式串是否出现，以及出现的位置。
//它的核心优点是避免了重复比较，时间复杂度是O(n + m) n为文本长度，m为模式串长度
//KMP算法的核心思想
//当我们在文本中匹配到一部分字符后，如果遇到了不匹配的字符，KMP利用“已经匹配的信息”来避免回溯文本指针
//KMP不像朴素匹配那样一旦失配就把文本指针回退，KMP通过“部分匹配表（next数组）”来决定模式串该往后跳多少

class Solution_3
{
public:
	int strStr(std::string haystack, std::string needle)
	{
		if (needle.size() == 0) return 0;
		std::vector<int> next = computeNext(needle);
		int j = 0;
		for (int i = 0; i < haystack.size(); ++i)
		{
			while (j > 0 && haystack[i] != needle[j])
				j = next[j - 1];
			if (haystack[i] == needle[j]) ++j;
			if (j == needle.size()) return i - needle.size() + 1;
		}
		return -1;
	}
	
private:
	std::vector<int> computeNext(const std::string& pattern)
	{
		std::vector<int> next(pattern.size(), 0);
		int j = 0;
		for (int i = 1; i < pattern.size(); ++i)
		{
			while (j > 0 && pattern[i] != pattern[j]) 
				j = next[j - 1];
			if (pattern[i] == pattern[j]) ++j;
			next[i] = j;
		}
		return next;
	}
};

int main()
{
	Solution_3 s;
	std::string haystack = "abcabacababcabababa";
	std::string needle = "ababa";
	s.strStr(haystack, needle);
	return 0;
}
