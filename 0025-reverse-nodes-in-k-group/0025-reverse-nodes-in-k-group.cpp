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
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head==nullptr||k<=1)return head;
       int count=1;
       ListNode *fin_head=nullptr, *pre=nullptr,*cur_head=head,*cur=head;
       while(cur!=nullptr&&cur->next!=nullptr){
        cur=cur->next;
        count++;
        if(count==k){
            ListNode *next_tmp=cur->next;
            cur->next=nullptr;

            ListNode *new_head=reverse(cur_head);
            if(cur_head==head)fin_head=new_head;
            else pre->next=new_head;

            pre=cur_head;
            pre->next=next_tmp;
            cur_head=next_tmp;
            cur=next_tmp;
            count=1;
        }
       }
       return fin_head;
    }
private:
    ListNode *reverse(ListNode *head){//使用前末尾节点需要断开
        ListNode *pre=nullptr ;
        ListNode *cur=head;
        while(cur!=nullptr){
            ListNode *tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
};