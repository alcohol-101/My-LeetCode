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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid=nums.size()/2;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=insert(nums,0,mid-1);
        root->right=insert(nums,mid+1,nums.size()-1);
        
        return root;
    }
    TreeNode* insert(vector<int>& nums,int left,int right){
        if(left>right)return nullptr;
        if(left==right)return new TreeNode(nums[left]);
        int mid=(left+right)/2;
        TreeNode *now=new TreeNode(nums[mid]);
        now->left=insert(nums,left,mid-1);
        now->right=insert(nums,mid+1,right);
        return now;
    }
};