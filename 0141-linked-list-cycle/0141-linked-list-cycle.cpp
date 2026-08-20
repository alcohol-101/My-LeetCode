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
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        if(head->next==nullptr)return false;
        vector<ListNode *>result;
        ListNode *node=head;
        while(node!=nullptr){
            result.push_back(node);
            auto it=find(result.begin(),result.end(),node->next);
            if(it!=result.end())return true;
            node=node->next;
        }
        return false;
    }
};