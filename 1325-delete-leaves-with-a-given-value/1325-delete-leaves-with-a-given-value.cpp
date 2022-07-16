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
    bool todelete(TreeNode* root,int t){
        if(!root->left && !root->right && root->val==t){
            return true;
        }
        return false;
    }
    void solve(TreeNode* root,int t){
        
        if(root->left) solve(root->left,t);
        if(root->right) solve(root->right,t);
        
        if(root->left && todelete(root->left,t)) root->left=NULL;
        if(root->right && todelete(root->right,t)) root->right=NULL;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* head=root;
        solve(root,target);
        if(todelete(head,target)){
            return NULL;
        }
        return head;
    }
};