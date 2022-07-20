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
    int solve(TreeNode* root,int& totsum){
        if(root==NULL){
            return 0;
        }
        
        int leftans=solve(root->left,totsum);
        int rightans=solve(root->right,totsum);
        
        int temp=abs(leftans-rightans);
        totsum+=temp;
        
        return root->val+leftans+rightans;
    }
    int findTilt(TreeNode* root) {
        int totsum=0;
        solve(root,totsum);
        return totsum;
    }
};