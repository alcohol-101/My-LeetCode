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
    int ans=-1001;
public:
    int maxPathSum(TreeNode* root) {
        gainMax(root);
        return ans;
    }
    int gainMax(TreeNode* root){
        if(!root)return -1001;
        int maxL=gainMax(root->left);
        int maxR=gainMax(root->right);
        ans=max({ans,maxL,maxR,root->val+maxL+maxR,root->val,root->val+max(maxL,maxR)});
        return max({root->val,root->val+max(maxL,maxR)});
    }
};