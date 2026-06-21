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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        int i=0;
        
        vector<vector<int>>result(1);
        bfs(root,0,result);
        return result;
    }

    void bfs(TreeNode* node,int i,vector<vector<int>>&r){
        if(!node)return;
        if(r.size()-1<i)r.emplace_back();
        r[i].push_back(node->val);
        bfs(node->left,++i,r);
        bfs(node->right,i,r);
    }
};