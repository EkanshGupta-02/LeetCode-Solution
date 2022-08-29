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
private:
    int solve(TreeNode* root,int& ans){
        if(root==NULL){
            return 0;
        }
        int leftpart = solve(root->left,ans);
        int rightpart = solve(root->right,ans);
        
        int leftans=0;
        int rightans=0;
        
        if(root->left!=NULL && root->val==root->left->val){
            leftans += 1 + leftpart;
        }
        
        if(root->right!=NULL && root->val==root->right->val){
            rightans += 1 + rightpart;
        }
        
        ans = max(ans,leftans+rightans);
        
        return max(leftans,rightans);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};