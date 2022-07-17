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
    TreeNode* maxvalue(TreeNode* root){
        if(root==NULL){
            return NULL;
        }

        TreeNode* temp=root;

        while(temp->right!=NULL){
            temp=temp->right;
        }

        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        
        if(root->val==key){
        //  0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
       //  1 child       
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
        
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            
       // 2child
            if(root->left!=NULL && root->right!=NULL){
                int pred=maxvalue(root->left)->val;
                
                root->val=pred;
                
                root->left=deleteNode(root->left,pred);
                return root;
            }
            
        }
        
        else if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        else{
            root->left = deleteNode(root->left,key);
        }
        return root;
    }
};