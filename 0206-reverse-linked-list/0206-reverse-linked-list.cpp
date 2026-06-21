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
    // ListNode* reverseList(ListNode* head) {
    //    ListNode *pre=nullptr;
    //    ListNode *cur=head;

    //    while(cur!=nullptr){
    //     ListNode * tmp=cur->next;
    //     cur->next=pre;
    //     pre=cur;
    //     cur=tmp;
    //    }

    //    return pre;
    // }

    ListNode* reverseList(ListNode* head){
        ListNode *newHead=nullptr;
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        newHead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
    }
    
        
    
};