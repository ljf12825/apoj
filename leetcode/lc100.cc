// LC100. Same Tree

/*
   Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

   Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

/*
   Example 1:
   Input: p = [1,2,3], q = [1,2,3]
   Output: true

   Example 2:
   Input: p = [1,2], q = [1,null,2]
   Output: false

   Example 3:
   Input: p = [1,2,1], q = [1,1,2]
   Output: false
*/

// Definition for a binary tree node.
#include <queue>
#include <vector>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Solution1 递归 DFS
class Solution1 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Solution2 用queue BFS
class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> que;
        que.push(p);
        que.push(q);

        while (!que.empty()) {
            TreeNode* node1 = que.front();
            que.pop();
            TreeNode* node2 = que.front();
            que.pop();

            if (node1 == nullptr && node2 == nullptr) continue;
            if (node2 == nullptr || node2 == nullptr) return false;
            if (node1->val != node2->val) return false;

            que.push(node1->left);
            que.push(node2->left);
            que.push(node1->right);
            que.push(node2->right);
        }

        return true;
    }
};

// Solution3 前序/中序/后序遍历 + 可视化空节点
class Solution3 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::vector<int> vec1, vec2;
        preorder(p, vec1);
        preorder(q, vec2);
        return vec1 == vec2;
    }

    void preorder(TreeNode* root, std::vector<int>& result) {
        if (root == nullptr) {
            result.push_back(INT_MIN); // 这样写的前提需要保证用例里没有INT_MIN，否则不成立
            return;
        }

        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
};
