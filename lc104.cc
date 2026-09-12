// LC104 Maximum Depth of Binary Tree

/*
   Given the `root` of a binary tree, return its maximum depth.

   A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/*
   Example1:\
   Input: root = [2,9,20,null,null,15,7]\
   Output: 3

   Example2:\
   Input: root = [1,null,2]\
   Output: 2
*/

#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(0), left(left), right(right) {}
};

// Solution1: 递归，核心本质是在左子树和右子树之间选择高度最高的
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

// Solution2: 显式模拟递归栈调用，本质和递归一样
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        std::stack<std::pair<TreeNode*, int>> sta;
        sta.push({root, 1});

        int ans = 0;

        while (!sta.empty()) {
            auto [node, depth] = sta.top();
            sta.pop();

            ans = std::max(ans, depth);

            if (node->left != nullptr) sta.push({node->left, depth + 1});
            if (node->right != nullptr) sta.push({node->right, depth + 1});
        }

        return ans;
    }
};

// Solution3: 层序遍历
class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        std::queue<TreeNode*> que;
        que.push(root);

        int depth = 0;

        while (!que.empty()) {
            int size = que.size();

            while (size--) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }

            depth++;
        }

        return depth;
    }
};
