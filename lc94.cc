// LC94. Binary Tree Inorder Traversal

/*
   Given the `root` of a binary tree, return the inorder traversal of its nodes' values.
*/

/*
   Example 1:
   Input: root = [1,null,2,3]
   Output: [1,3.2]

   Example 2:
   Input: root = [1,2,3,4,5,null,8,null,6,7,9]
   Output: [4,2,6,5,7,1,3,9,8]

   Example 3:
   Input: root = []
   Output: []

   Example 4:
   Input: root = [1]
   Output: [1]
*/

#include <stack>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution1 递归，通过系统自动创建的栈帧保存节点信息
class Solution1 {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return vec;
        inorderTraversal(root->left);
        vec.push_back(root->val);
        inorderTraversal(root->right);
        return vec;
    }

private:
    std::vector<int> vec;
};

// Solution2 迭代，手动维护栈记录节点信息
class Solution2 {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        std::stack<TreeNode*> sta;
        TreeNode *cur = root;

        while (cur != nullptr || !sta.empty()) {
            while (cur != nullptr) {
                sta.push(cur);
                cur = cur->left;
            }

            cur = sta.top();
            sta.pop();

            vec.push_back(cur->val);

            cur = cur->right;
        }

        return vec;
    }
};
