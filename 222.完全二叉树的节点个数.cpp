/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) { 
               
        TreeNode *LNode = root; 
        TreeNode *RNode = root;
        int rLevel = 0; 
        int lLevel = 0;
        while (LNode != nullptr){
            lLevel++;
            LNode = LNode->left;
        }
         while (RNode != nullptr){
             rLevel++;
            RNode = RNode->right;
        }
        if (rLevel == lLevel){
            return (int)pow(2,lLevel) - 1;
        }
        return countNodes(root->left) + countNodes(root->right)+1;
        
    }
};
// @lc code=end

