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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *>a;
        a.push(root);
        while(a.front()!=nullptr){
            a.push(a.front()->left);
            a.push(a.front()->right);
            a.pop();
        }
        while(a.size()!=0){
            if(a.front()!=nullptr)return false;
            a.pop();
        }
        return true;
    }
};