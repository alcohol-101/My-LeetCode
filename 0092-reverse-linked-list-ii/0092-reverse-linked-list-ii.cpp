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
        if(left==right)return head;
        ListNode *dum=new ListNode();
        dum->next=head;
        int count=0;

        ListNode *p=new ListNode(),*t=new ListNode();
        ListNode *tmp=dum;
        while(tmp!=nullptr){
            if(count==left-1)p=tmp;
            
            tmp=tmp->next;
            ++count;

            if(count==right+1)t=tmp;
        }

        fz(p,t);
        
        return dum->next;
    }
    
    void fz(ListNode* prev, ListNode* tail) {
       ListNode *first=prev->next;
       if(first==tail)return;

       ListNode *pre=prev;
       ListNode *cur=pre->next;
       while(cur!=tail){
         ListNode *nex=cur->next;
         cur->next=pre;
         pre=cur;
         cur=nex;
       }
       prev->next=pre;
       first->next=tail;
    }
};