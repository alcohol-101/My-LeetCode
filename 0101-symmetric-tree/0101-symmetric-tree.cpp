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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }

    bool isMirror(TreeNode*l,TreeNode*r){
        if(!l&&!r)return true;//均为空
        else if(!l||!r)return false;//半是空
        return (l->val==r->val)//均非空
                &&isMirror(l->left,r->right)
                &&isMirror(l->right,r->left);
    }
};