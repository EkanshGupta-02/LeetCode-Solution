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
    void solve(TreeNode* root,vector<int>mp,int &cnt){
        if(root==NULL){
            return ; 
        }
        
        mp[root->val]++;
        
        int odd_count=0;
        if(root->left==NULL && root->right==NULL){
            for(auto m:mp){
                if(m%2){
                    odd_count++;
                }
            }
            if(odd_count<=1){
                    cnt++;
            }
            return;
        }
        
        solve(root->left,mp,cnt);
        solve(root->right,mp,cnt);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt=0;
        vector<int>mp(10,0);
        solve(root,mp,cnt);
        
        return cnt;
    }
};