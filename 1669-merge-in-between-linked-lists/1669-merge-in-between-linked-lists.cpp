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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head1=list1;
        ListNode* tail1=list1;
        ListNode* tail2=list2;
        
        while(tail2->next!=NULL){
            tail2=tail2->next;
        }
        a=a-1;
        while(a--){
            head1=head1->next;
        }
        
        while(b--){
            tail1=tail1->next;
        }
        
        head1->next=list2;
        tail2->next=tail1->next;
        
        
        return list1;
        
    }
};