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
    bool isValidBST(TreeNode* root) {
        
        return isBST(root,LLONG_MIN,LLONG_MAX);
    }

    bool isBST(TreeNode*n,long long int min,long long int max){
        if(n==nullptr)return true;
        if(n->val>=max||n->val<=min)return false;

        return isBST(n->left,min,n->val)&&isBST(n->right,n->val,max);
    }
};