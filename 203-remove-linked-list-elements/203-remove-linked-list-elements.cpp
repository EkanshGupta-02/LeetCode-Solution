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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL){
            return NULL;
        }
        
        if(head->next==NULL){
            if(head->val==val){
                return NULL;
            }
            else{
                return head;
            }
        }
        while(head!=NULL && head->val==val){
            ListNode* t=head;
            head=head->next;
            delete(t);    
        }
        
        ListNode* temp=head;
        ListNode* prev=NULL;
        
        while(temp!=NULL){
            prev=temp;
            temp=temp->next;
            if(temp!=NULL){
            if(temp->val==val){
                prev->next=temp->next;
                temp=prev;
            }
            }
        }
        
        return head;
    }
};