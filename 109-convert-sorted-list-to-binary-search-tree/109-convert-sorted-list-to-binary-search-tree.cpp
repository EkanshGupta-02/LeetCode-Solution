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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* listtoBST(vector<ListNode*>&node,int s,int e){
        if(s>e){
            return NULL;
        }
        
        int mid=s+(e-s)/2;
        
        TreeNode* root = new TreeNode(node[mid]->val);
        
        root->left=listtoBST(node,s,mid-1);
        root->right=listtoBST(node,mid+1,e);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*>nodelist;
        
        for(ListNode* curr=head;curr!=NULL;curr=curr->next){
            nodelist.push_back(curr);
        }
        
        int i=0;
        int j=nodelist.size()-1;
        
        return listtoBST(nodelist,i,j);
    }
};