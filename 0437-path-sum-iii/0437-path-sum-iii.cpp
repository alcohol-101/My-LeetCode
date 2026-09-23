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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        int count=0;
        long long int sum=0;
        bl(root,count,sum,targetSum);
        count+=pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
        return count;
    }
    void bl(TreeNode*root,int &count,long long int &sum,int targetSum){
        if(root==nullptr)return;
        sum+=root->val;
        if(targetSum==sum)++count;
        bl(root->left,count,sum,targetSum);
        bl(root->right,count,sum,targetSum);
        sum-=root->val;
    }
};