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
    TreeNode* successor(TreeNode* root){
        TreeNode* temp=root->right;
        if(temp==NULL){
            return temp;
        }
        while(temp->left!=NULL && temp->left!=root){
            temp=temp->left;
        }
        
        return temp;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        int sum=0;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->right==NULL){
                sum+=curr->val;
                curr->val=sum;
                curr=curr->left;
            }
            
            else{
                TreeNode* succ=successor(curr);
                
                if(succ->left==NULL){
                    succ->left=curr;
                    curr=curr->right;
                }
                else{
                    succ->left=NULL;
                    sum+=curr->val;
                    curr->val=sum;
                    curr=curr->left;
                }
            }
        }
        
        return root;
    }
};