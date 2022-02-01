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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
         ListNode* forward=NULL;
        
        while(curr!=NULL){
          forward =curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    
    ListNode *getmid(ListNode*head){
        
        ListNode* curr=head->next;
        ListNode* mid=head;
    
        while(curr != NULL && curr->next!=NULL){
            curr=curr->next->next;
            mid=mid->next;
        }
        
        return mid;
        
    }
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL){
            return true;
        }
        
        if(head->next==NULL){
            return true;
        }
        
        ListNode* mid=getmid(head);
        
        ListNode* temp=mid->next;
        
        mid->next=reverse(temp);
        
        ListNode* head1=head;
        ListNode* head2=mid->next;
        
        while(head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
            
        }
         
        temp=mid->next;
        mid->next=reverse(temp);
        
        
        return true;

    }
};