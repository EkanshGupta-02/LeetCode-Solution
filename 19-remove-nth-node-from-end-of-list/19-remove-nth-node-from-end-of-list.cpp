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
    int length(ListNode* head){
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || (head->next==NULL && n==1)){
            return NULL;
        }
        int len = length(head);
        
        ListNode* temp1=head;
            ListNode* temp2=NULL;
        
        for(int i=0;i<len-n;i++){
            temp2=temp1;
            temp1=temp1->next;
        }
        if(temp2==NULL){
            return head->next;
        }
        temp2->next = temp1->next;
        delete(temp1);
        
        return head;
    }
};