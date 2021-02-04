/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
/**
算法步骤如下：

首先调用 construct(nums, 0, n)，其中 nn 是数组 numsnums 的长度。

在索引范围 (l:r-1)(l:r−1) 内找到最大值的索引，将 nums[max\_i]nums[max_i] 作为根节点。

调用 construct(nums, l, max_i) 创建根节点的左孩子。递归执行此操作，创建根节点的整个左子树。

类似的，调用 construct(nums, max_i + 1, r) 创建根节点的右子树。

方法 construct(nums, 0, n) 返回最大二叉树的根节点。

链接：https://leetcode-cn.com/problems/maximum-binary-tree/solution/zui-da-er-cha-shu-by-leetcode/
**/
class Solution {
public:
    int max(vector<int> &nums, int l, int r)
    {
        int maxNum = l;
        for(int i = l; i < r; i++){
            if(nums[maxNum] < nums[i])
                maxNum = i;
        }
        return maxNum;

    }
    TreeNode *construct(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            return nullptr;
        }
        
        int max_index = max(nums,l,r);
        TreeNode* root = new TreeNode(nums[max_index]);
        root->left =  construct(nums,l,max_index);
        root->right =  construct(nums,max_index + 1,r);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int n = nums.size();
        return construct(nums,0,n);
    }
};
// @lc code=end

