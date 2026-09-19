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
        if (head == nullptr) return head;
        
        // dummy 作为可能的"第 0 个节点"，统一处理 left==1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // 找 p = 第 left-1 个节点
        ListNode* p = dummy;
        for (int i = 1; i < left; i++) p = p->next;
        
        // 找 t = 第 right+1 个节点（可能为 nullptr）
        ListNode* t = head;
        for (int i = 0; i < right; i++) t = t->next;
        
        // 反转 p->next 到 t 之前
        fz(p, t);
        
        return dummy->next;
    }
    
    void fz(ListNode* prev, ListNode* tail) {
        ListNode* first = prev->next;  // 区间第一个，反转后变区间尾
        if (first == tail) return;     // 区间为空（left > right 之类，正常不会发生）
        
        ListNode* pre = prev;
        ListNode* cur = first;
        while (cur != tail) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        prev->next = pre;     // 前驱 -> 新区间头
        first->next = tail;   // 原区间头（现区间尾）-> 后继
    }
};
