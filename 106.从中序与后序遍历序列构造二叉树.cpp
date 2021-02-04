/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
class Solution
{
private:
    unordered_map<int,int> index;
public:
    TreeNode *buildTreeByInorderAndPostorder(const vector<int> &inorder, int inorder_left,int inorder_right,const vector<int> &postorder,int postorder_left,int postorder_right)
    {
        if (inorder_left > inorder_right)
        {
            return nullptr; 
        }
        
        //后序遍历最后一个就是根节点位置
        int postorder_root = postorder_right;
        //中序遍历根节点位置
        int inorder_root = index[postorder[postorder_root]];
        //左子树的数量
        int left_subTree_size = inorder_root - inorder_left;
        //构建root节点
        TreeNode* root = new TreeNode(postorder[postorder_root]);
        // 递归地构造左子树，并连接到根节点
        // 后序序遍历中「从左边界开始的 size_left_subtree - 1」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = buildTreeByInorderAndPostorder(inorder, inorder_left, inorder_root - 1, postorder,postorder_left, postorder_left + left_subTree_size - 1);
         // 后序序遍历中「从 左边界 left_subTree_size 开始到有边界 - 1 」个元素就对应了中序遍历中「从 根节点定位+1到右边界」的元素
        root->right = buildTreeByInorderAndPostorder(inorder, inorder_root + 1, inorder_right, postorder, postorder_left + left_subTree_size,postorder_right - 1);
        return root;


    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        size_t count = inorder.size();
        for (size_t i = 0; i < count; i++)
        {
            /* code */
            index[inorder[i]] = i;
        }
        return buildTreeByInorderAndPostorder(inorder,0,count-1,postorder,0,count-1);
        

    }
};
// @lc code=end
