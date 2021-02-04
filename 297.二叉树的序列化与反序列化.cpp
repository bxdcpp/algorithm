/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:
  

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            m_data += (m_nullObject + m_key);
            return;
        }

        m_data += (to_string(root->val) + m_key);
        inorder(root->left);
        inorder(root->right);
    }

    TreeNode* buidTree(std::queue<std::string>& qTree)
    {
        string strValue = qTree.front();
        if (strValue == m_nullObject)
        {
            qTree.pop();
            return nullptr;
        }
            
        TreeNode *root = new TreeNode(stoi(strValue));
        qTree.pop();
        root->left = buidTree(qTree);
        root->right = buidTree(qTree);

        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        inorder(root);
        return m_data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data == "")
            return nullptr;
        //std::cout << data << std::endl;

        // 将字符串存入到队列中
        std::queue<std::string> q;
        std::string str;

        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == ',')
            {
                q.push(str); //当前字符串压入队列
                str.clear();
            }
            else
                str.push_back(data[i]);
        }

        return buidTree(q);
    }

 
private:
    string m_key = ",";
    string m_nullObject = "null";
    string m_data = "";
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

