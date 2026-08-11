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
        if(root->left==nullptr&&root->right==nullptr)return true;
        if(root->left==nullptr&&root->right!=nullptr)return false;
        else if(root->left!=nullptr&&root->right==nullptr)return false;
        deque<TreeNode *>q;
        q.push_back(root->left);
        q.push_back(root->right);
        if(root->left->val!=root->right->val)return false;
        while(q.size()!=0){
            if (q.size() % 2 != 0) return false;
            deque<TreeNode *>l,r;
            while(!q.empty()){
                TreeNode *ll=q.front()->left,*lr=q.front()->right,
                         *rl=q.back()->left,*rr=q.back()->right;
                bool first=false,end=false;
                if(!ll&&!rr)first=true;
                else if(!ll||!rr)return false;
                if(!lr&&!rl)end=true;
                else if(!rl||!lr)return false;
                if(!first){
                    if(ll->val!=rr->val)return false;
                }
                if(!end){
                    if(rl->val!=lr->val)return false;
                }
                if(ll)l.push_back(ll);
                if(lr)l.push_back(lr);
               
                q.pop_front();
                
                if(rr)r.push_back(rr);
                if(rl)r.push_back(rl);
                q.pop_back();
            }
            
            reverse(r.begin(),r.end());
            q.insert(q.end(),l.begin(),l.end());
            q.insert(q.end(),r.begin(),r.end());
        }

        return true;
    }
};