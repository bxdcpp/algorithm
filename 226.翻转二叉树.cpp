/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            /* code */
            return nullptr;
        }
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
// @lc code=end

