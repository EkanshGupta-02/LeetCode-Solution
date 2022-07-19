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
//     Leftview of binary tree
    void solve(TreeNode* root,vector<int>& ans,int level){
        if(root==NULL){
            return;
        }
        
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int>ans;
        solve(root,ans,0);
        return ans[ans.size()-1];
    }
};