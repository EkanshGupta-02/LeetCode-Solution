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
    int getlength(ListNode* head){
        int cnt=0;
        
        ListNode* temp=head;
        
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        
        if(k==0 || head==NULL){
            return head;
        }
        
        int len=getlength(head);
        k=k%len;
        
        while(temp->next!=NULL){
            temp=temp->next;
        }
        
        temp->next=head;
        
        temp=temp->next;
        
        for(int i=1;i<=len-k-1;i++){
            temp=temp->next;
        }
        
        ListNode* newhead=temp->next;
        
        temp->next=NULL;
        
        return newhead;
        
    }
};