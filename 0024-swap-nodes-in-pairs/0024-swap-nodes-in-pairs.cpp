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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;

        ListNode*fir=head,*sec=head->next;
        fir->next=sec->next;
        sec->next=fir;
        ListNode*pre=fir;

        while(pre->next&&pre->next->next){
            ListNode*first=pre->next,*second=pre->next->next;
            pre->next=second;
            first->next=second->next;
            second->next=first;
            pre=first;
        }
       return sec;
    }
};