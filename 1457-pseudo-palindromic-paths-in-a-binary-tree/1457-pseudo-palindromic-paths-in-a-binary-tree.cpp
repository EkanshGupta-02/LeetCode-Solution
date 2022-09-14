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
   void solve(TreeNode* root,int cnt,int& ans){
       if(root==NULL){
           return;
       }
       
       cnt ^= 1<<root->val;
       
       if(root->left==NULL && root->right==NULL && (cnt&(cnt-1))==0){
           ans++;
       }
       
      solve(root->left,cnt,ans);
       solve(root->right,cnt,ans);
   }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        solve(root,0,ans);
        
        return ans;
    }
};