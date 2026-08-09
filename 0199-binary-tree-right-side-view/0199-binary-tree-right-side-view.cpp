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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        if(root->left==nullptr&&root->right==nullptr)return {root->val};

        vector<vector<int>>result;
        queue<TreeNode *>q;
        q.push(root);

        int levelSize=1;
   
        while(!q.empty()){
            levelSize=q.size();
            vector<int>tmp;

            for(int i=0;i<levelSize;i++){
                TreeNode * now=q.front();
                q.pop();
                if(now->left!=nullptr)
                q.push(now->left);
                if(now->right!=nullptr)
                q.push(now->right);
                tmp.push_back(now->val);

            }

            result.push_back(tmp);
        }

        vector<int>ans;
        for(auto v:result){
            ans.push_back(v.back());
        }
        return ans;
    }
};