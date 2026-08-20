/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)return NULL;
        if(head->next==nullptr)return NULL;
        vector<ListNode *>r;
        ListNode * node=head;
        while(node!=nullptr){
            r.push_back(node);
            auto it=find(r.begin(),r.end(),node->next);
            if(it!=r.end())return *it;
            node=node->next;
        }
        return NULL;
    }
};