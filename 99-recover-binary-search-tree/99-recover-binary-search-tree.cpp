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
    priority_queue<int,vector<int>,greater<int>>pq;
    void traverse(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        pq.push(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    void solve(TreeNode* root){
        
        if(root==NULL){
            return;
        }
        solve(root->left);
        int t=pq.top();
        pq.pop();
        if(root->val!=t) root->val=t;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        traverse(root);
        solve(root);
    }
};