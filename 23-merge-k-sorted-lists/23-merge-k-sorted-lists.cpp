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
    class cmp{
        public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        ListNode* dummy = new ListNode(-1);
        ListNode* head=dummy;
        
        for(auto list:lists){
            if(list){
                pq.push(list);
            }
        }
        
        while(!pq.empty()){
            ListNode* node=pq.top();
            dummy->next=node;
            pq.pop();
            dummy=dummy->next;
            
            if(dummy->next){
                pq.push(dummy->next);
            }
        }
        
        dummy->next=NULL;
        
        return head->next;
    }
};