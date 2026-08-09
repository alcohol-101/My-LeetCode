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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)return nullptr;
        if(preorder.size()==1)return new TreeNode(preorder[0]);

        TreeNode* root=new TreeNode(preorder[0]);
        int i_tmp;
        for(int i=0;i<preorder.size();++i){
            if(inorder[i]==preorder[0]){
                i_tmp=i;
                break;
            }
        }

        root->left=bl(preorder,inorder,1,i_tmp,0,i_tmp-1);
        root->right=bl(preorder,inorder,i_tmp+1,inorder.size()-1,i_tmp+1,inorder.size()-1);
        
        return root;
       
    }

    TreeNode * bl(vector<int>& preorder, vector<int>& inorder,int pl,int pr,int il,int ir){
        if(pl>pr)return nullptr;

        TreeNode *root=new TreeNode(preorder[pl]);
        int i_tmp;
        for(int i=il;i<=ir;i++){
            if(preorder[pl]==inorder[i]){
                i_tmp=i;
                break;
            }
        }

        root->left=bl(preorder,inorder,pl+1,i_tmp-il+pl,il,i_tmp-1);
        root->right=bl(preorder,inorder,i_tmp-il+pl+1,ir-il+pl,i_tmp+1,ir);
        
        return root;
       
    }
};