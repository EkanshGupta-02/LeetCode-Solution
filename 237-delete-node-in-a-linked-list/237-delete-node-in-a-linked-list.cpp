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
    void deleteNode(ListNode* node) {
        ListNode* temp=node;
        
        while(temp && temp->next){
            if(temp && temp->next && !temp->next->next){
                temp->val=temp->next->val;
                temp->next=NULL;
            }
            else if(temp && temp->next){
                int t=temp->val;
                temp->val=temp->next->val;
                temp->next->val=t;
                temp=temp->next;
            }
        }
        
    }
};