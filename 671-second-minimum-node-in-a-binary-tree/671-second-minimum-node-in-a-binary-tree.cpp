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
    void traversal(TreeNode* root,vector<int>&q){
        if(root==NULL){
            return;
        }
        
        q.push_back(root->val);
        traversal(root->left,q);
        traversal(root->right,q);
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> v;
        traversal(root,v);
       sort(v.begin(),v.end());
        int n=v.size();
        int i=0;
        int x=v[i];
        while(i<n && v[i]==x)
        {
            i++;
        }
        if(i<n)
        return v[i];
        return -1;
    }
};