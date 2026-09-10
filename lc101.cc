// LC101. Symmetric Tree

/*
   Given the `root` of a binary tree, check whether it is a mirror of itself(i.e., symmetric around its center).
*/

/*
   Example 1:
   Input: root = [1,2,2,3,4,4,3]
   Output: true

   Example 2:
   Input: root = [1,2,2,null,3,null,3]
   Output: false
*/

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Solution1
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirrorTree(root->left, root->right);
    }

    bool isMirrorTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left);
    }
};
