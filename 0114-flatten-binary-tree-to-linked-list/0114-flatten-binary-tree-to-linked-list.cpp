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
    void flatten(TreeNode* root) {
        if(!root)return;
        TreeNode*r=root->right;
        TreeNode*l=root->left;
        if(r!=nullptr&&l!=nullptr){
            flatten(l);
            flatten(r);
            root->right=l;
            root->left=nullptr;
            while(l->right!=nullptr){
                l=l->right;
            }
            l->right=r;//l的底部接上右子树
        }
        else if(l!=nullptr){
            flatten(l);
            root->right=l;
            root->left=nullptr;
        }
        else if(r!=nullptr){
            flatten(r);
        }
    }
    
};