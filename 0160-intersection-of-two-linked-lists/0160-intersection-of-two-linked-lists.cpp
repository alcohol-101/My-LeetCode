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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)return NULL;

        ListNode *pa=headA,*pb=headB;
        while(pa!=pb){
            pa=(pa==nullptr)?headB:pa->next;
            pb=(pb==nullptr)?headA:pb->next;
        }

        return pa;
    }
};