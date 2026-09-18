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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root->left&&!root->right)return 0;
        int now_max=0;
        depth(root,now_max);
        return now_max;
    }

    int depth(TreeNode*root,int& m){
        if(!root)return 0;
        
        int l=depth(root->left,m);
        int r=depth(root->right,m);

        m=max(m,l+r);
        return max(r,l)+1;
    }
};