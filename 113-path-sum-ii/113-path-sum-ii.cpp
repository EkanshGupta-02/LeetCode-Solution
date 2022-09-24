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
    vector<vector<int>>ans;
    vector<int>v;
    
    void solve(TreeNode* root,int t){
        if(root==NULL){
            return ;
        }
        
        if(root->left==NULL && root->right==NULL){
            if(t-root->val==0){
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        
        v.push_back(root->val);
        
        if(root->left){
            solve(root->left,t-root->val);
        }
        
        if(root->right){
            solve(root->right,t-root->val);
        }
        
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return {};
        }
        
        solve(root,targetSum);
        
        return ans;
    }
};