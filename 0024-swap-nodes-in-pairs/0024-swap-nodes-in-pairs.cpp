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
        if(!head)return nullptr;
        if(head->next==nullptr)return head;
        ListNode*now=head;
        ListNode*pre=new ListNode();
        pre->next=head;
        ListNode*ans=pre;
        bool isout=false;
        while(now!=nullptr){
            if(now->next==nullptr)break;//奇数，直接跳出
            if(now->next->next==nullptr){
                isout=true;
                break;
            }
            ListNode* tmp=now->next->next;
            ListNode* tmp_next=now->next;
            pre->next=tmp_next;
            now->next->next=now;
            now->next=tmp;
            
            pre=now;
            now=tmp;
        }
        if(isout){//偶数，翻转最后的一对
            pre->next=now->next;
            now->next->next=now;
            now->next=nullptr;
        }
        return ans->next;
    }
};