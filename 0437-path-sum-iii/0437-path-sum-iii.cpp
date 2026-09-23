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
    int target;
    unordered_map<long long int,int>prefix;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        target=targetSum;
        prefix[0]=1;
        
        return dfs(root,0);
    }
    int dfs(TreeNode*root,long long int curSum){
        int count=0;
        if(root==nullptr)return count;
        curSum+=root->val;

        count+=prefix[curSum-target];
        prefix[curSum]++;
        count+=dfs(root->left,curSum);
        count+=dfs(root->right,curSum);
        prefix[curSum]--;

        return count;
    }
};