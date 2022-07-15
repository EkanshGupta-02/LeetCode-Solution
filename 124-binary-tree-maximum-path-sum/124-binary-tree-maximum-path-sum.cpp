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
    int solve(TreeNode* root,int& sum){
        if(root==NULL){
            return 0;
        }
        
        int leftans=solve(root->left,sum);
        int rightans=solve(root->right,sum);
        
        int option1 = max(max(leftans,rightans)+root->val,root->val);
        int option2 = max(option1,(leftans+rightans+root->val));
        
        sum=max(option2,sum);
        
        return option1;
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        
        solve(root,sum);
        
        return sum;
    }
};