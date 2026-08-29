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
    bool isPalindrome(ListNode* head) {
        int n=0;
        ListNode *tmp=head;
        while(tmp!=nullptr){
            tmp=tmp->next;
            n++;
        }
        int b=(n+1)/2;
        
        ListNode *mid=head;
        while(b>0){
            mid=mid->next;
            b--;
        }
        ListNode *p=nullptr,*cur=mid;
        while(cur!=nullptr){
            ListNode *t=cur->next;
            cur->next=p;
            p=cur;
            cur=t;
        }
        tmp=head;
        while(p!=nullptr&&tmp!=mid){
            if(tmp->val!=p->val)return false;
            tmp=tmp->next;
            p=p->next;
        }

       
        return true;

    }
};