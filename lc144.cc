// LC144. Binary Tree Preorder Traversal

/*
   Given the `root` of a binary tree, return the preorder traversal of its nodes' value
*/

/*
   Example1:\
   Input: root = [1,null,2,3]\
   Output: [1,2,3]

   Example2:\
   Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]\
   Output: [1,2,3,4,5,6,7,3,8,9]

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

// Solution1：迭代
class Solution1 {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return result;
        else {
            result.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }

        return result;
    }

private:
    std::vector<int> result;
};

// Solution2：stack模拟调用栈
class Solution2 {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (!root) return result;

        std::stack<TreeNode*> st; // 存指针要比存完整的栈帧占用空间小
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            result.push_back(node->val);

            // FILO
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return result;
    }
};

// Solution3：Morris Traversal 线索连法：左子树最右 -> cur；访问时机：建立线索时
class Solution3 {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }

                if (!pre->right) {
                    pre->right = cur;
                    result.push_back(cur->val);
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    cur = cur->right;
                }
            }
        }

        return result;
    }
};

// Solution4：线索树
