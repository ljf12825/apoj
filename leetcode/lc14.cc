// LC14.Longest Common Prefix


/*
Write a function to find the longest common prefix string amongst an array of strings

If there is no common prefix, return an empty string `""`.

Example 1:

Input: strs = ["flower", "flow", "flight"]\
Output: "fl"


Example 2:

Input: strs = ["dog", "racecar", "car"]
Output: ""
*/

#include <vector>
#include <string>
#include <algorithm>

// Solution1：横向扫描
class Solution1
{
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs)
	{
		if (!strs.size()) return "";
		std::string prefix = strs[0];
		int count = strs.size();
		for (int i = 1; i < count; ++i)
		{
			prefix = longestCommonPrefix(prefix, strs[i]);
			if (!prefix.size()) break;
		}
		return prefix;
	}
	std::string longestCommonPrefix(const std::string& str1, const std::string& str2)
	{
		int length = std::min(str1.size(), str2.size());
		int index = 0;
		while (index < length && str1[index] == str2[index])
		{
			++index;
		}
		return str1.substr(0, index);
	}
};

// Solution2: 纵向扫描
class Solution2
{
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs)
	{
		if (!strs.size()) return "";
		int length = strs[0].size();
		int count = strs.size();
		for (int i = 0; i < count; ++i)
		{
			char c = strs[0][i];
			for (int j = 1; j < count; ++j)
			{
				if (i == strs[j].size() || strs[j][i] != c)
					return strs[0].substr(0, i);
			}
		}
		return strs[0];
	}
};

// Solution3:分治
class Solution3
{
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs)
	{
		if (!strs.size()) return "";
		else return longestCommonPrefix(strs, 0, strs.size() - 1);
	}

	std::string longestCommonPrefix(const std::vector<std::string>& strs, int start, int end)
	{
		if (start == end) return strs[start];
		else
		{
			int mid = (start + end) / 2;
			std::string lcpLeft = longestCommonPrefix(strs, start, mid);
			std::string lcpRight = longestCommonPrefix(strs, mid + 1, end);
			return commonPrefix(lcpLeft, lcpRight);
		}
	}

	std::string commonPrefix(const std::string& lcpLeft, const std::string& lcpRight)
	{
		int minLength = std::min(lcpLeft.size(), lcpRight.size());
		for (int i = 0; i < minLength; ++i)
		{
			if (lcpLeft[i] != lcpRight[i]) return lcpLeft.substr(0, i);
		}
		return lcpLeft.substr(0, minLength);
	}
};

// Solution4:二分查找
class Solution4
{
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs)
	{
		if (!strs.size()) return "";
		int minLength = std::min_element(strs.begin(), strs.end(), [](const std::string& s, const std::string& t) {return s.size() < t.size(); })->size();
		int low = 0, high = minLength;
		while (low < high)
		{
			int mid = (high - low + 1) / 2 + low;
			if (isCommonPrefix(strs, mid)) low = mid;
			else high = mid - 1;
		}
		return strs[0].substr(0, low);

	}

	bool isCommonPrefix(const std::vector<std::string>& strs, int length)
	{
		std::string str0 = strs[0].substr(0, length);
		int count = strs.size();
		for (int i = 1; i < count; ++i)
		{
			std::string str = strs[i];
			for (int j = 0; j < length; ++j)
			{
				if (str0[j] != str[j]) return false;
			}
		}
		return true;
	}
};

// Solution5:sort排序后比较首尾
class Solution5
{
	std::string longestCommonPrefix(std::vector<std::string>& strs)
	{
		std::sort(strs.begin(), strs.end());
		std::string ans = "";
		for (int i = 0; i < strs[0].size() && i < strs[strs.size() - 1].size(); ++i)
		{
			if (strs[0][i] == strs[strs.size() - 1][i]) ans += strs[0][i];
			else break;
		}
		return ans;
	}
};
