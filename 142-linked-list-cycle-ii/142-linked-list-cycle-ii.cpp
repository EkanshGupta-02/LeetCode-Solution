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
    ListNode *detectCycle(ListNode *head) {
        
        if(head ==NULL || head->next==NULL){
            return NULL;
        }
        
        ListNode* p=head;
        ListNode* q=head;
        
        do{
             p=p->next;
            if(p){
                p=p->next;
            }
            q=q->next;
            if(p ==  NULL){
                return NULL;
            }
        }while(p!=q);
        
        
        if(!p || !q){
            return NULL;
        }
        
        p=head;
      
        while(p !=q)
            p=p->next, q=q->next;
        return p;
        
    }
};