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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>result;
        deque<TreeNode*>dq;
        dq.push_back(root);
        bool isLeft=true;
        while(!dq.empty()){
            vector<int>current;
            int levelSize=dq.size();
            reverse(dq.begin(),dq.end());
            if(isLeft){
                for(int i=0;i<levelSize;i++){
                    current.push_back(dq.front()->val);
                    TreeNode*node=dq.front();
                    dq.pop_front();
                    if(node->left)dq.push_back(node->left);
                    if(node->right)dq.push_back(node->right);
                }
            }
            else{
                for(int i=levelSize-1;i>=0;--i){
                    current.push_back(dq.front()->val);
                    TreeNode*node=dq.front();
                    dq.pop_front();
                    if(node->right)dq.push_back(node->right);
                    if(node->left)dq.push_back(node->left);
                }
            }
            isLeft=!isLeft;
            result.push_back(current);
        }
        return result;
    }
};
