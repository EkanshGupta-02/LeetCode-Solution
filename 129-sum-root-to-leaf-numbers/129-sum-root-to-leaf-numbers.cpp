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
    void solve(TreeNode* root,vector<int>&ans,int value){
        if(root==NULL){
            return;
        }
        
        value=value*10+root->val;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(value);
            return;
        }
        
        solve(root->left,ans,value);
        solve(root->right,ans,value);
    } 
    int sumNumbers(TreeNode* root) {
        vector<int>ans;
        solve(root,ans,0);
        return accumulate(ans.begin(),ans.end(),0);
    }
};