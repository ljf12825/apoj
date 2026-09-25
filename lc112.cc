// LC112. Path Sum

/*
   Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a root-to-leaf path such that adding up all the values along the path equals `targetSum`.

   A leaf is a node with no children.
*/

/*
   Example1:\
   Input: root = [5,4,8,11,null,13,4,,7,2,null,null,null,1], targetSum = 22\
   Output: true\
   Explanation: 5->4->11->2

   Example2:\
   Input: root = [1,2,3], targetSum = 5
   Output: false

   Example3:\
   Input: root = [], targetSum = 0
   Output: false
*/

// Definition for a binary tree node.

#include <stack>
#include <utility>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// MySolution 这是错误的
class MySolution1 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 问题1：当Input为root = [], targetSum == 0时返回true，应该返回false
        // 问题2：返回true的判定条件是叶子节点且路径和为targetSum，现在是以targetSum == 0作为前提，推到一个空节点上导致无法判断上一个节点是否为叶子节点
        if (!root && targetSum == 0) return true;
        else if (!root && targetSum != 0) return false;
        else if (root && targetSum == 0) return false;
        else return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

class MySolution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (flag == 0 && root == nullptr) return false; // 用flag为0的情况判断树根为nullptr的情况，比较丑陋
        if (!root && targetSum == 0) { // 但是问题2仍然存在
            flag++;
            return true;
        } else if (!root && targetSum != 0) {
            flag++;
            return false;
        } else if (root && targetSum == 0) {
            flag++;
            return false;
        } else {
            flag++;
            return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        }

    }

private:
    int flag = 0;
};

// Solution1：递归，在叶子节点处判断targetSum的情况，一举两得
class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) return targetSum == root->val;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

// Solution2：迭代，DFS + 栈，手动保存状态
class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        std::stack<std::pair<TreeNode*, int>> sta;
        sta.push({root, targetSum});
        
        while (!sta.empty()) {
            auto [node, sum] = sta.top();
            sta.pop();

            if (node->left == nullptr && node->right == nullptr) {
                if (sum == node->val) return true;
            }
            if (node->right) sta.push({node->right, sum - node->val});
            if (node->left) sta.push({node->left, sum - node->val});
        }
        return false;
    }
};
