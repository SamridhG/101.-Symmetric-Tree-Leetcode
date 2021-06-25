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
    vector<int>A,B;
    void preA(TreeNode* root)
    {
        if(root==NULL)
        {
            A.push_back(-101);
        }
        else
        {
            A.push_back(root->val);
            preA(root->left);
            preA(root->right);
        }
    }
    void preB(TreeNode* root)
    {
        if(root==NULL)
        {
            B.push_back(-101);
        }
        else
        {
            B.push_back(root->val);
            preB(root->right);
            preB(root->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        preA(root->left);
        preB(root->right);
        if(A.size()!=B.size())
        {
            return false;
        }
        return A==B?true:false;
    }
        
};
