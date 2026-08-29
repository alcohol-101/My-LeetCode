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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        int dep=now_dep(root);
        return dep;
    }
    int now_dep(TreeNode *node){
        int count=0;
        if(node!=nullptr)count++;
        else return 0;
        int l=now_dep(node->left);
        int r=now_dep(node->right);
        count+= l>r?l:r;
        return count;
    }
};