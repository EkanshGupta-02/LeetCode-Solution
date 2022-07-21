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
    void solve(TreeNode* root,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        
        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        vector<int>inorder;
        solve(root,inorder);
        
        TreeNode* ans=new TreeNode(0);
        TreeNode* curr=ans;
        
        for(int i=0;i<inorder.size();i++){
            TreeNode* temp=new TreeNode(inorder[i]);
            curr->right=temp;
            curr=temp;
        }
        
        return ans->right;
    }
};