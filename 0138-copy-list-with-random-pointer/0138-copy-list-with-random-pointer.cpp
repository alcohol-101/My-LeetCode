/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        unordered_map<Node*,Node*>mp;
        Node* now=head;
        while(now){
            mp[now]=new Node(now->val);
            now=now->next;
        }
        now=head;
        while(now){
            if(now->next)mp[now]->next=mp[now->next];
            if(now->random)mp[now]->random=mp[now->random];
            now=now->next;
        }
        return mp[head];
    }
};