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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==nullptr)return false;
        if(!root->left&&!root->right&&root->val==targetSum)return true;
        int tmp=root->val;
        
        bool l=dfs(root->left,targetSum,tmp);
        bool r=dfs(root->right,targetSum,tmp);

        return l||r;
    }

    bool dfs(TreeNode *root,int target,int cur){
        if(!root)return false;
        
        if(!root->left&&!root->right){
            if(root->val+cur==target)return true;
            else return false;
        }
        else{
            bool l,r;
            if(root->left)l=dfs(root->left,target,cur+root->val);
            else l=false;
            if(root->right)r=dfs(root->right,target,cur+root->val);
            else r=false;

            return l||r;
        }
    }

    
};