/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> subTreeMap;
        vector<TreeNode *> ret;
        traverse(root,subTreeMap, ret);
        return ret;
    }
    string traverse(TreeNode *root, unordered_map<string, int>& subTreeMap, vector<TreeNode *>& ret)
    {
        if (root == nullptr)
        {
            return "#";
        }

        string leftStr = traverse(root->left,subTreeMap,ret);
        string rightStr = traverse(root->right,subTreeMap,ret);
        string subTree = leftStr + "," + rightStr + "," + to_string(root->val);

        if (subTreeMap.count(subTree)) //[]: 若当前元素不存在时，会自动插入一个访问元素，并返回一个mapped_type值
        {
            subTreeMap[subTree]++;
        }

        if (subTreeMap[subTree] == 1) //在第二次遇到相同的元素，count()方法就返回1
        {
            ret.push_back(root);
        }

        return subTree;
    }
};
// @lc code=end

