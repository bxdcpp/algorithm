/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
class Solution
{
public:
    /*bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
    bool helper(TreeNode* root,long long min,long long max)
    {
        if(!root) return true;
        if(root->val <= min || root->val >= max) return false;
        return helper(root->left,min,root->val) && helper(root->right,root->val,max);
    }*/
    //非递归
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> s;
        TreeNode *p;
        s.push(root);
        long long min = LONG_MIN;
        while (!s.empty())
        {
            while (p = s.top())
                s.push(p->left);
            s.pop();
            if (!s.empty())
            {
                p = s.top();
                if (p->val <= min)
                    return false;
                min = p->val;
                s.pop();
                s.push(p->right);
            }
        }
        return true;
    }
};
// @lc code=end
