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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* p3 = dummy;
    while(p1 != NULL && p2 != NULL){
            if(p1->val < p2->val){
                p3->next =p1;
                p1= p1->next;
            }
            else{
                p3->next = p2;
                p2 = p2->next;
                }
            p3 = p3->next;
    }
    while(p1 != NULL){
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
    while(p2 != NULL){
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    return dummy->next;
  }
    ListNode* getmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* mid=getmid(head);
        ListNode* left=head;
        
        ListNode* right=mid->next;
        
        mid->next=NULL;
        
        left=sortList(left);
        right=sortList(right);
        
        ListNode* sorted=merge(left,right);
        return sorted;
    }
};