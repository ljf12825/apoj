// LC110. Balanced Binary Tree

/*
   Given a binary tree, determine if it is height-balanced(A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.)
*/

/*
   Example1:
   Input: root = [3,9,20,null,null,15,7]
   Output: true

   Example2:
   Input: root = [1,2,2,3,3,null,null,4,4]
   Output: false

   Example3:
   Input: root = []
   Output: true
*/

// Definition for a binary tree node
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <unordered_map>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Solution1 Top-Down DFS，写一个判断树高的辅助函数，递归对每个节点判断它的左右子树是否平衡; 时间复杂度最坏O(n^2)，空间复杂度O(n)
class Solution1 {
public:
    bool isBalanced (TreeNode* root) {
        if (root == nullptr) return true;
        bool isCurrentBalanced = abs(treeheight(root->left) - treeheight(root->right)) <= 1;
        return isCurrentBalanced && isBalanced(root->left) && isBalanced(root->right);
    }

    int treeheight(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + std::max(treeheight(node->left), treeheight(node->right));
    }
};

// Solution2：Bottom-Up DFS 后序遍历，结合后续遍历，在递归计算子树高度的同时判断是否平衡，如果不平衡，直接向上返回 -1，时间复杂度O(n)，空间复杂度O(h)，h为树高
class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        int left = checkHeight(node->left);
        if (left == -1) return -1;

        int right = checkHeight(node->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;;

        return 1 + std::max(left, right);
    }
};

// Solution3：基于Post-Order栈遍历 + 哈希表记录高度
class Solution3 {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        std::stack<TreeNode*> st;
        std::unordered_map<TreeNode*, int> heights;
        TreeNode* lastVisited = nullptr;
        TreeNode* curr = root;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* node = st.top();
            if (node->right && node->right != lastVisited) curr = node->right;
            else {
                int leftH = heights[node->left];
                int rightH = heights[node->right];

                if (abs(leftH - rightH) > 1) return false;

                heights[node] = 1 + std::max(leftH, rightH);
                lastVisited = node;
                st.pop();
            }
        }

        return true;
    }
};
