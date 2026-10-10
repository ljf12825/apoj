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

#include <stack>
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

// Solution1：递归
class Solution1 {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return result;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        result.push_back(root->val);

        return result;
    }

private:
    std::vector<int> result;
};

// Solution2：迭代
class Solution2 {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> sta;
        TreeNode* cur = root;
        TreeNode* lastvisited = nullptr;

        while (cur != nullptr || !sta.empty()) {
            while (cur != nullptr) {
                sta.push(cur);
                cur = cur->left;
            }

            TreeNode* node = sta.top();

            if (node->right != nullptr && node->right != lastvisited) cur = node->right;
            else {
                res.push_back(node->val);
                sta.pop();
                lastvisited = node;
            }
        }

        return res;
    }
};

// Solution3：Morris Traversal
class Solution3 {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;

        TreeNode dummy(0);
        dummy.left = root;

        TreeNode* cur = &dummy;

        while (cur != nullptr) {
            if (cur->left == nullptr) cur = cur->right;
            else {
                TreeNode* pred = cur->left;

                while (pred->right != nullptr && pred->right != cur) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    collectReverse(cur->left, pred, res);

                    pred->right = nullptr;
                    cur = cur->right;
                }
            }
        }

        return res;
    }

private:
    void reverseRight(TreeNode* from, TreeNode* to) {
        if (from == to) return;

        TreeNode* x = from;
        TreeNode* y = from->right;
        TreeNode* z = nullptr;

        while (true) {
            z = y->right;
            y->right = x;
            x = y;
            y = z;

            if (x == to) break;
        }
    }

    void collectReverse(TreeNode* from, TreeNode* to, std::vector<int>& res) {
        reverseRight(from, to);

        TreeNode* node = to;

        while (true) {
            res.push_back(node->val);
            if (node == from) break;
            node = node->right;
        }

        reverseRight(to, from);
    }
};
