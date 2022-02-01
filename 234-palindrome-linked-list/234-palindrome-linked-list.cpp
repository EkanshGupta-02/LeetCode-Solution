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
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL){
            return false;
        }
        
        if(head->next==NULL){
            return true;
        }
        
        ListNode* curr=head;
    
        vector<int> a;
        
        while(curr != NULL){
            
            a.push_back(curr->val);
            curr=curr->next;
            
        }
        
        int s=0;
        int e=a.size()-1;
        
        while(s<=e){
            if(a[s]!=a[e]){
                return false;
            }
            s++;
            e--;
        }
        
        
        return true;

    }
};