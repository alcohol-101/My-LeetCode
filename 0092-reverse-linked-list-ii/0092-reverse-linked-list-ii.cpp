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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dum=new ListNode();
        dum->next=head;
        int count=0;

        ListNode*p=dum;
        while(count!=left-1){
            ++count;
            p=p->next;
        }

        ListNode *cur=p->next;
        for(int i=0;i<right-left;i++){
            ListNode*nxt=cur->next;
            cur->next=nxt->next;
            nxt->next=p->next;
            p->next=nxt;
        }

        return dum->next;
    }
    
    
};