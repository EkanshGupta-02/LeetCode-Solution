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
        
        if(head==NULL ){
            return head;
        }
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(left>1){
            prev=curr;
            curr=curr->next;
            left--;
            right--;
        }
        
        ListNode* p=prev;
        ListNode* q=curr;
        ListNode* r=NULL;
        
        while(right>0){
            r=curr->next;
            curr->next=prev;
            prev=curr;
            curr=r;
            right--;
        }
        
        if(p!=NULL){
            p->next=prev;
        }
        else{
            head=prev;
        }
        
        q->next=curr;
        
        return head;
    }
};