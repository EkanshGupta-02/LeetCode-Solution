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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        
        ListNode* temp=head;
        
        int cnt=0;
        
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        
        ListNode* p=head;
        ListNode* q=NULL;
        
        int pt=cnt-n;
        if(pt==0){
            return head->next;
        }
        while(pt){
            q=p;
            p=p->next;
            pt--;
        }
        
        q->next=p->next;
        
        delete p;
        
        return head;
    }
};