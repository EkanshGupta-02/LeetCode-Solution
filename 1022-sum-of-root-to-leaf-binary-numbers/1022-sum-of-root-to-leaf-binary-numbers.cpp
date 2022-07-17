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
    void solve(TreeNode* root,string prev){
        if(root->left==NULL && root->right==NULL){
            prev+=to_string(root->val);
            ans.push_back(prev);
        }
        
        char ch='0'+root->val;
        prev+=ch;
        
        if(root->left)
        solve(root->left,prev);
        if(root->right)
        solve(root->right,prev);
    }
    int sumRootToLeaf(TreeNode* root) {
        string prev;
        solve(root,prev);
        
        long long res=0;
        
        for(auto i:ans){
            int temp=0;
            for(int j=i.size()-1;j>=0;j--)
            {
                if(i[j]=='1')
                    temp+=pow(2, i.size()-j-1);
            }
            res+=temp;
        }
        
        return res;
    }
};