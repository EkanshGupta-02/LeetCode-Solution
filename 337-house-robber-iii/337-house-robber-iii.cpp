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
    int solveRec(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int leftans = 0;
        int rightans = 0;
        
        if(root->left){
            leftans = solveRec(root->left->left) + solveRec(root->left->right);
        }
        
        if(root->right){
            rightans = solveRec(root->right->left) + solveRec(root->right->right);
        }
        
        return max(root->val+leftans+rightans , solveRec(root->left) + solveRec(root->right));
    }
    
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&mp){
        if(root==NULL){
            return 0;
        }
        
        if(mp[root]){
            return mp[root];
        }
        
        int leftans = 0;
        int rightans = 0;
        
        if(root->left){
            leftans = solve(root->left->left,mp) + solve(root->left->right,mp);
        }
        
        if(root->right){
            rightans = solve(root->right->left,mp) + solve(root->right->right,mp);
        }
        
        return mp[root] = max(root->val+leftans+rightans , solve(root->left,mp) + solve(root->right,mp));
    }
public:
    int rob(TreeNode* root) {
       unordered_map<TreeNode*,int>mp;
        return solve(root,mp);
    }
};