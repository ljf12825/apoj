// LC67.Add Binary

/*
   Given two binary strings `a` and `b`, return their sum as a binary string

   Example 1:
   Input: a = "11", b = "1"
   Output: "100"

   Example 2:
   Input: a = "1010", b = "1011"
   Output: "10101"
*/

#include <string>
#include <algorithm>

class Solution1 {
public:
    std::string addBinary(std::string a, std::string b) {
        bool flag = false;
        std::string ls;
        std::string ss;
        if (a.size() > b.size()) {
            ls = a;
            ss = b;
        } else {
            ls = b;
            ss = a;
        }
        int lsindex = ls.size() - 1;
        int ssindex = ss.size() - 1;

        while (ssindex >= 0) {
            if (flag) {
                    if (ls[lsindex] == '1' && ss[ssindex] == '1') ls[lsindex] = '1';
                    else if (ls[lsindex] != ss[ssindex]) ls[lsindex] = '0';
                    else if (ls[lsindex] == '0' && ss[ssindex] == '0') {
                        ls[lsindex] = '1';
                        flag = false;
                    }
                } else {
                    if (ls[lsindex] == '1' && ss[ssindex] == '1') {
                       ls[lsindex] = '0';
                        flag = true;
                    } else if (ls[lsindex] == '0' && ss[ssindex] == '0') ls[lsindex] = '0';
                    else if (ls[lsindex] != ss[ssindex]) ls[lsindex] = '1';
                }
                --ssindex;
                --lsindex;
        }

        while (lsindex >= 0) {
            if (flag) {
                if (ls[lsindex] == '1') ls[lsindex] = '0';
                else {
                    ls[lsindex] = '1';
                    flag = false;
                }
            }
            --lsindex;
        }

        if (flag) ls.insert(ls.begin(), '1');

        return ls;
    }
};

class Solution2 {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            // sum 是每位的结果 sum = a[i] + b[j] + carry
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            result.push_back('0' + sum % 2); // 当前位
            carry = sum / 2; // 进位
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};

class Solution3
{
public:
	std::string addBinary(std::string a, std::string b)
	{
		std::string ans;
		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), b.end());
		int n = std::max(a.size(), b.size()), carry = 0; //进位记录

		for (size_t i = 0; i < n; ++i)
		{
			carry += i < a.size() ? (a.at(i) == '1') : 0;
			carry += i < b.size() ? (b.at(i) == '1') : 0;
			ans.push_back((carry % 2) ? '1' : '0');
			carry /= 2;
		}
		if (carry) ans.push_back(1);
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
};
