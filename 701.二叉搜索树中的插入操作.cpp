/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         // 找到空位置插入新节点
    if (root == nullptr) return new TreeNode(val);
    // if (root->val == val)
    //     BST 中一般不会插入已存在元素
    if (root->val < val) 
        root->right = insertIntoBST(root->right, val);
    if (root->val > val) 
        root->left = insertIntoBST(root->left, val);
    return root;
    }
};
// @lc code=end

