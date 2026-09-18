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
        vector<Node*>old_node;
        Node *now=head;
        while(now){
            old_node.push_back(now);
            now=now->next;
        }
        vector<Node*>new_node;
        new_node.resize(2*old_node.size());
        unordered_map<Node*,int>old_index;
        //初步构建
        for(int i=0;i<2*old_node.size();i+=2){
            new_node[i]=old_node[i/2];
            new_node[i+1]=new Node(old_node[i/2]->val);
            old_index[new_node[i]]=i;
        }
        //处理next
         for(int i=1;i<2*old_node.size();i+=2){
            if(i!=2*old_node.size()-1)new_node[i]->next=new_node[i+2];
            if(new_node[i-1]->random){
                int ran=old_index[new_node[i-1]->random];
                new_node[i]->random=new_node[ran+1];
            }
        }
        return new_node[1];
    }
};