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
    ListNode* swapPairs(ListNode* head) {   
        
         if(head == NULL || head->next == NULL) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        prev->next = curr->next;
        curr->next = prev;
        head = curr;
        curr = prev->next;
        prev->next = swapPairs(curr);
        return head;
        
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
        
//         ListNode* p=head;
//         ListNode* q=head->next;
//         ListNode* prev=NULL;
        
//         ListNode* r=NULL;
        
        
//         while(q != NULL || p!=NULL){
            
//             if(q->next){
//                r=q->next;
//             }
            
//             if(p==head){
//                 prev=q;
//                 q->next=p;
//                 p->next=r;
//                 head=q;
//             }
            
//             else{
//                 prev->next=q;
//                 q->next=p;
//                 p->next=r;
//                 prev=p;
//             }
            
//             p=r;
//             q=r->next;
//         }
        
//         return head;
    }
};