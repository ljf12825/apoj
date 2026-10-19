// LC17. Letter Combinations of a Phone Number

/*
    Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
*/

/*
    Example1:\
    Input: digits = "23"\
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

    Example2:\
    Inut: digits = "2"\
    Output: ["a", "b", "c"]
*/

/*
    Constraints:\
    - `1 <= digits.length <= 4`
    - `digits[i]` is a digit in the range `['2', '9']`.
*/

#include <string>
#include <utility>
#include <vector>
// Solution1：DFS回溯，建立数字到字母的映射，然后对输入字串逐位做DFS：每层选一个数字对应的一个字母，选完所有数字就得到一个组合
class Solution1 {
public:
    std::vector<std::string> letterCombination(std::string digits) {
        std::vector<std::string> mapping = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        std::vector<std::string> res;
        std::string path;
        backtrack(digits, 0, mapping, path, res);
        return res;
    }

private:
    void backtrack(const std::string& digits, int idx, const std::vector<std::string>& mapping, std::string& path, std::vector<std::string>& res) {
        if (idx == digits.size()) {
            res.push_back(path);
            return;
        }

        const std::string& letters = mapping[digits[idx] - '0'];
        for (char c : letters) {
            path.push_back(c);
            backtrack(digits, idx + 1, mapping, path, res);
            path.pop_back();
        }
    }
};

// Solution2: BFS
class Solution2 {
public:
    std::vector<std::string> letterCombination(std::string digits) {
        if (digits.empty()) return {};

        std::vector<std::string> mp = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        std::vector<std::string> res = {""};
        for (char d : digits) {
            std::vector<std::string> next;
            for (const std::string& s : res)
                for (char c : mp[d - '0'])
                    next.push_back(s + c);
            res = std::move(next);
        }

        return res;
    }
};
