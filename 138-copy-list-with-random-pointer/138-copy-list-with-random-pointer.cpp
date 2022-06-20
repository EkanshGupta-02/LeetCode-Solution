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
    unordered_map<Node*,Node*>mp;
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }        
        
        Node* newhead = new Node(head->val);
        
        mp[head]=newhead;
        
        newhead->next=copyRandomList(head->next);
        
        newhead->random=mp[head->random];
        
        return newhead;
    }
};