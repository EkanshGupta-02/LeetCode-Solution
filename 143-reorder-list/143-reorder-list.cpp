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
    ListNode* getmid(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
            ListNode* mid=getmid(head);
        
            ListNode* first=head;
        
            ListNode* second=mid->next;
        
            mid->next=NULL;
        
        second=reverse(second);
            
        while(second!=NULL){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            
            first->next=second;
            second->next=temp1;
            
            first=temp1;
            second=temp2;
        }
        
    }
};