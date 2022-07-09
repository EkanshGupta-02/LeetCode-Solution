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
    pair<int,bool> solve(TreeNode* root){
        if(root==NULL){
            return make_pair(0,true);
        }
        pair<int,bool> leftans=solve(root->left);                             pair<int,bool> rightans=solve(root->right);
    
        bool diff=abs(leftans.first-rightans.first)<=1;
        
        if(leftans.second && rightans.second && diff){
           return make_pair(max(leftans.first,rightans.first)+1,true);
        }
        else{
            return make_pair(max(leftans.first,rightans.first)+1,false);
        }
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool>ans=solve(root);
        
        return ans.second;
    }
};