// LC108. Convert Sorted Array to Binary Search Tree

/*
   Given an integer array `nums` where the elements are sorted in ascending order, convert it to a height-balanced binary serach tree.
*/

/*
   Example1:
   Input: nums = [-10,-3,0,5,9]
   Output: [0.-3,-10,null,5]
   
   Example2:
   Input: nums = [1,3]
   Output: [3,1]
*/

// 这道题最开始看到是懵的，因为在我的印象里我不记得从数组构造二叉树有什么特殊方法，观察了这道题给出的示例，发现根节点就是数组的中间节点，左子节点 < 根节点 < 右子节点；然后想到递归取中，而选择数组的中间节点作为根节点正好满足让二叉树平衡

#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return buildnode(nums, 0, nums.size());
    }

    TreeNode* buildnode(std::vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildnode(nums, left, mid - 1);
        root->right = buildnode(nums, mid + 1, right);

        return root;
    }
};
