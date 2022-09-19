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
    bool solve(TreeNode* root,long long int mini,long long int maxi){
        if(root==NULL){
            return true;
        }
        
       
        
        if(root->val>mini && root->val<maxi){
            bool leftpart = solve(root->left,mini,root->val);
            bool rightpart = solve(root->right,root->val,maxi);
            
            return leftpart && rightpart;
        }
        else{
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return solve(root,LONG_MIN,LONG_MAX);
    }
};