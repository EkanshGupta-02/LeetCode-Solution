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
        if(head==NULL){
            return NULL;
        }
        ListNode* prev = NULL;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        
        if(l2==NULL){
            return l1;
        }
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* res = NULL;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode* temp = res;
            res = new ListNode(sum % 10);
            res->next = temp;
            carry = (sum > 9) ? 1 : 0;
        }
        return res; 
        
    }
};