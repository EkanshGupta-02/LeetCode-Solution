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
        
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    
    ListNode* getmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* curr=head;
        
        ListNode* mid=getmid(head);
        
        ListNode* res=mid->next;
        mid->next=NULL;
        
        res=reverse(res);
        int mx=INT_MIN;
        while(curr !=NULL || res!=NULL){
            int sum=curr->val+res->val;
            mx=max(mx,sum);
            curr=curr->next;
            res=res->next;
        }
        
        return mx;
    }
};