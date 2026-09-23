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
    int kthSmallest(TreeNode* root, int k) {
        if(root->right==nullptr&&root->left==nullptr)return root->val;
        vector<int>ans;
        inorder(root,ans,k);
        return ans[k-1];

    }

    void inorder(TreeNode *root,vector<int>&a,int k){
        if(root==nullptr||a.size()==k)return;
        inorder(root->left,a,k);
        a.push_back(root->val);
        if(a.size()==k)return;
        inorder(root->right,a,k);
    }
};