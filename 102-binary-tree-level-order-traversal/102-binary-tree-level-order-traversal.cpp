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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        
        vector<vector<int>>ans;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            
            while(size--){
                TreeNode* cur=q.front();
                int val=cur->val;
                temp.push_back(val);
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            ans.push_back(temp); 
        }
        
        return ans;
    }
};