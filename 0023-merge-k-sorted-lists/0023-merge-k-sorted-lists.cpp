/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;

        ListNode*tmp=lists[0];
        for(int i=1;i<lists.size();i++){
            tmp=merge(tmp,lists[i]);
        }

        return tmp;

    }

    ListNode* merge(ListNode*a,ListNode*b){
        ListNode*tmp=new ListNode();
        ListNode*ans=tmp;
        while(a&&b){
            if(a->val<=b->val){
                tmp->next=a;
                tmp=tmp->next;
                a=a->next;
            }
            else{
                tmp->next=b;
                tmp=tmp->next;
                b=b->next;
            }
        }
        tmp->next=a?a:b;
        return ans->next;
    }
   

};