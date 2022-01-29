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
        
        if(head==NULL || left==right){
            return head;
        }
        
        ListNode* d= new ListNode();
        d->next=head;
        
     ListNode* p=d;
        for(int i=1;i<left;i++){
            p=p->next;
        }
        
        ListNode* q=p->next;
        
        while(left<right){
            ListNode* rev=q->next;
            q->next=rev->next;
            rev->next=p->next;
            p->next=rev;
            left++;
        }
        
        return d->next;
    }
};