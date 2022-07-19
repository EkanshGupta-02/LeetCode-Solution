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
    void solve(TreeNode* root,unordered_map<int,int>& mp){
        if(root==NULL){
            return;
        }
        
        mp[root->val]++;
        solve(root->left,mp);
        solve(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        solve(root,mp);     
        
        vector<int>ans;
        int maxi=INT_MIN;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        
        for(auto i:mp){
            if(i.second==maxi){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};