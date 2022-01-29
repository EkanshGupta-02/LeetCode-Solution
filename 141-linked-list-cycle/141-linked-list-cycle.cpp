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
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode* p=head->next;
        ListNode* q=head;
        
        while(p!=q){
            p=p->next;
            if(p){
                p=p->next;
            }
            q=q->next;
            if(p ==  NULL){
                return false;
            }
        }
        return true;
        
    }
};