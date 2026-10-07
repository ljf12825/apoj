// LC145. Binary Tree Postorder Traversal

/*
   Given the `root` of a binary tree, return the postorder traversal of its nodes' values.
*/

/*
   Example1:\
   Input: root = [1,null,2,3]\
   Output: [3,2,1]

   Example2:\
   Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]\
   Output: [4,6,7,5,2,9,8,3,1]

   Example3:\
   Input: root = []\
   Output: []

   Example4:\
   Input: root = [1]\
   Output: [1]
*/

#include <vector>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Solution1：迭代
class Solution1 {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return result;
        else {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            result.push_back(root->val);
        }

        return result;
    }

private:
    std::vector<int> result;
};
