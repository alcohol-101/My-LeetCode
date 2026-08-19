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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return nullptr;
        if(head->next==nullptr)return nullptr;
        vector<ListNode*>a;
        ListNode * node=head;
        while(node!=nullptr){
            a.push_back(node);
            node=node->next;
        }
        ListNode *aim=a[a.size()-n];
        ListNode *qian;
        if(a.size()!=n)qian=a[a.size()-n-1];
        else{
            return head->next;
        }
        qian->next=aim->next;
        aim->next=nullptr;
        delete aim;
        return head;
    }
};