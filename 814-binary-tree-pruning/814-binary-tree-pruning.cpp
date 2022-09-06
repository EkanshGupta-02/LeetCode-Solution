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
    bool solve(TreeNode* root){
        if(root==NULL){
            return false;
        }
        bool leftpart = solve(root->left);

        bool rightpart = solve(root->right);

        if(!leftpart) root->left = NULL;
        if(!rightpart) root->right = NULL;
        return root->val==1 || leftpart || rightpart;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        return solve(root)?root:NULL;
    }
};