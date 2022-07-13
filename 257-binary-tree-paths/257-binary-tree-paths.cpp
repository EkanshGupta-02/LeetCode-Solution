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
    vector<string>ans;
    
    void solve(TreeNode* root,string st){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            st+=to_string(root->val);
            ans.push_back(st);
            return;
        }
        
        st+=to_string(root->val);
        st+="->";
        
        solve(root->left,st);
        solve(root->right,st);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string st;
        solve(root,st);
        
        return ans;
    }
};