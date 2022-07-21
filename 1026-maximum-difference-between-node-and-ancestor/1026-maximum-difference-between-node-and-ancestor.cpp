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
    void solve(TreeNode* root,int currmax,int currmin,int& maxdiff){
        if(root==NULL){
            return;
        }
        
        int temp=max(abs(root->val-currmax),abs(root->val-currmin));
        maxdiff=max(maxdiff,temp);
        
        currmax=max(currmax,root->val);
        currmin=min(currmin,root->val);
        solve(root->left,currmax,currmin,maxdiff);
        solve(root->right,currmax,currmin,maxdiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxdiff=INT_MIN;
        solve(root,root->val,root->val,maxdiff);
        
        return maxdiff;
    }
};