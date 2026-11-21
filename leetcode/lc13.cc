// title: LC13.Roman to Integet
/*
Roman numerals are repesented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`

| Symbol | Value |
| - | - |
| I | 1 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`.\
The number `27` is written as `XXVII`, which is `XX` + `V` + `II`

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we substract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `I` can be placed before `V`(5) and `X`(10) to make 4 and 9
- `X` can be placed before `L`(50) and `C`(100) to make 40 and 90
- `C` can be placed before `D`(500) and `M`(1000) to make 400 and 900

Given a roman numeral, convert it to an integer


Example 1:\
Input: s = "III"\
Output: 3\
Explanation: III = 3

Example 2:\
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V = 5, III = 3

Example 3:\
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4
*/

// 题解

#include <unordered_map>

// 使用unordered_map
class Solution
{
public:

    std::unordered_map<char, int> table =
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

	int romanToInt(std::string s)
	{
		int ans = 0;
		for (int i = 0; i < s.size() - 1; ++i)
		{
			int x = table[s[i]], y = table[s[i + 1]]; // 核心就是判断当前位置和后面一位，从而决定当前位置的含义
			ans += x < y ? -x : x;
		}
		return ans + table[s.back()];
	}
};

// 使用哈希表通常涉及动态分配的节点和指针访问，访问成本相对较高
// 使用哈希表，大致会经历
/*
   char
   v
   hash
   v
   bucket 定位
   v
   节点访问
   v
   比较 key
   v
   得到 value
*/
// 针对本题目，只有七个固定的场景，可以使用switch结构，编译器可将其优化成比较 + 跳转，甚至生成跳转表，条件移动等形式
// 甚至可以使用数组
// 甚至
/*
   'I' = 73
   'V' = 86
   'X' = 88
   'L' = 76
   'C' = 67
   'D' = 68
   'M' = 77
*/
// 可以使用一个很小的查找表
// 但是数据量很小，性能差距并不大
// 不使用unordered_map

class Solution2 {
    int romanToInt(std::string s)
    {
        auto getValue = [](char& value)->int{
                switch (value)
                {
                case'I':
                    return 1;
                case 'V':
                    return 5;
                case 'X':
                    return 10;
                case 'L':
                    return 50;
                case 'C':
                    return 100;
                case 'D':
                    return 500;
                case 'M':
                    return 1000;
                default:
                    return 0;
                }
        };

        int sum = 0;

        for (int i = 0; i < s.size() - 1; ++i)
        {
            sum += (getValue(s[i + 1]) > getValue(s[i]) ? (-getValue(s[i])) : getValue(s[i]));
        }

        sum += getValue(s.back());
        return sum;
    }
};

