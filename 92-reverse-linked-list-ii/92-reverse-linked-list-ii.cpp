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
        if(!head) return head;
        
        ListNode* curr=head;
            ListNode* prev=NULL;
        
        for(int i=0;i<left-1;i++){
            prev=curr;
            curr=curr->next;
        }
        
        int cnt=0;
        ListNode* forward;
        ListNode* temp=curr;
        ListNode* prev2=NULL;
        
        while(cnt<right-left+1){
            forward=temp->next;
            temp->next=prev2;
            prev2=temp;
            temp=forward;
            cnt++;
        }
        
        if(!prev) head=prev2;
        else{
            prev->next=prev2;
        }
        
        curr->next=temp;
        
        return head;
    }
};