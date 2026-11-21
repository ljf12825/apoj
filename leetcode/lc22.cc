// LC22. Generate Parentheses

/*
   Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

/*
   Example1:\
   Input: n = 3\
   Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]

   Example2:\
   Input: n = 1\
   Output: ["()"]
*/

/*
   Constraints:\
   - `1 <= n <= 8`
*/

#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
// Solution1：递归，传值，不用手动撤销但每层都发生拷贝
class Solution1 {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string path;
        backtrack(res, path, 0, 0, n);
        return res;
    }

private:
    void backtrack(std::vector<std::string>& res, std::string path, int left, int right, int n) {
        if (path.size() == 2 * n) {
            res.push_back(path);
            return;
        }

        if (left < n) backtrack(res, path + '(', left + 1, right, n);

        if (right < left) backtrack(res, path + ')',left, right + 1, n);
    }

};

// Solution2：递归，传引用，需要手动撤销，但额外空间占用小
class Solution2 {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string path;
        backtrack(res, path, 0, 0, n);
        return res;
    }

private:
    void backtrack(std::vector<std::string>& res, std::string& path, int left, int right, int n) {
        if (path.size() == 2 * n) {
            res.push_back(path);
            return;
        }

        if (left < n) {
            path.push_back('(');
            backtrack(res, path, left + 1, right, n);
            path.pop_back();
        }

        if (right < left) {
            path.push_back(')');
            backtrack(res, path, left, right + 1, n);
            path.pop_back();
        }
    }
};

// Solution3：显式栈模拟DFS
class Solution3 {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::stack<std::tuple<std::string, int, int>> st;
        st.push({"", 0, 0});

        while (!st.empty()) {
            auto [path, left, right] = st.top();
            st.pop();

            if (path.size() == 2 * n) {
                res.push_back(path);
                continue;
            }

            if (right < left) st.push({path + ')', left, right + 1});

            if (left < n) st.push({path + '(', left + 1, right});
        }

        return res;
    }
};

// Solution4：队列BFS
class Solution4 {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::queue<std::tuple<std::string, int, int>> qu;
        qu.push({"", 0, 0});

        while (!qu.empty()) {
            auto [path, left, right] = qu.front();
            qu.pop();

            if (path.size() == 2 * n) {
                res.push_back(path);
                continue;
            }

            if (left < n) qu.push({path + '(', left + 1, right});
            if (right < left) qu.push({path + ')', left, right + 1});
        }

        return res;
    }
};

// Solution5：DP / 按长度递推，n对括号的任意合法串，一定能拆成`'(' + A + ')' + B`，其中A是i对括号的合法串，B是n-1-i对括号的合法串，依据是卡特兰数的递推结构
class Solution5 {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::vector<std::string>> dp(n + 1);
        dp[0] = {""};

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (const std::string& inner : dp[j]) {
                    for (const std::string& outer : dp[i - 1 - j]) {
                        dp[i].push_back("(" + inner + ")" + outer);
                    }
                }
            }
        }

        return dp[n];
    }
};
