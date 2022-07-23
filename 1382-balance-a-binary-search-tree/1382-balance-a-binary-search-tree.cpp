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
    
    TreeNode* inordertoBST(int s,int e,vector<int>inorder){
        if(s>e){
            return NULL;
        }
        
        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(inorder[mid]);
        root->left=inordertoBST(s,mid-1,inorder);
        root->right=inordertoBST(mid+1,e,inorder);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        solve(root,inorder);
        
        return inordertoBST(0,inorder.size()-1,inorder);
    }
};