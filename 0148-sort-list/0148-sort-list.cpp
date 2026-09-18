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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow=head,*fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*mid=slow->next;
        slow->next=nullptr;
        ListNode *left=sortList(head);
        ListNode *right=sortList(mid);
        return merge(left,right);
    }
    ListNode* merge(ListNode *a,ListNode* b){
        ListNode* now=new ListNode();
        ListNode* pre=now;
        while(a&&b){
            if(a->val<=b->val){
                now->next=a;
                a=a->next;
            }
            else{
                now->next=b;
                b=b->next;
            }
            now=now->next;
        }
        now->next=a?a:b;
        return pre->next;
    }
};