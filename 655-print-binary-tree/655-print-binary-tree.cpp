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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        
        int leftans=height(root->left);
        int rightans=height(root->right);
        
        return 1 + max(leftans,rightans);
    }
    
    void traverse(vector<vector<string>>&ans,int m,int n,int i,int j,TreeNode* root,int height){
        if(i==m || j==n){
            return ;
        }
        if(root==NULL){
            return;
        }
        
        ans[i][j]=to_string(root->val);
        
        traverse(ans,m,n,i+1,j-pow(2,height-i-1),root->left,height);
        traverse(ans,m,n,i+1,j+pow(2,height-i-1),root->right,height);
        return;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int m = h;
        int n = pow(2,(h))-1;
        
        vector<vector<string>>ans(m,vector<string>(n,""));
        
        int i=0;
        int j=(n-1)/2;
        traverse(ans,m,n,i,j,root,h-1);
        
        return ans;
    }
};