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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        TreeNode *l=root->left,*r=root->right;
        if(!l&&!r)return root;
        if(r)root->left=invertTree(r);
        else root->left=nullptr;
        if(l)root->right=invertTree(l);
        else root->right=nullptr;
        return root;
    }
};