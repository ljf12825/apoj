// LC111. Minimum Depth of Binary Tree

/*
   Given a binary tree, find its minimum depth.\
   The minimum is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/*
   Example1:
   Input: root = [3,9,20,null,null,15,7]
   Output: 2

   Example2:
   Input: root = [2,null,3,null,4,null,5,null,6]
   Output: 5
*/

// Definition for a binary tree node.
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Solution1 DFS递归，时间复杂度O(n)，空间复杂度O(n)
/*
   - 遇到叶子 -> 返回1
   - 只有左边 -> 走左边
   - 只有右边 -> 走右边
   - 左右都有 -> 取最小值
*/

class Solution1 {
public:
    int minDepth(TreeNode* root) { // 无法标记叶子节点就把非所有非叶子节点的情况写出来
        if (!root)  return 0;
        if (!root->right) return minDepth(root->left);
        if (!root->left) return minDepth(root->right);
        return std::min(minDepth(root->left), minDepth(root->right));
    }
};
