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
    void reverse(vector<int>&ans){
        if(ans.size()==0){
            return;
        }
        int i=0;
        int j=ans.size()-1;
        
        while(i<j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
                TreeNode* curr=q.front();
                int val=curr->val;
                q.pop();
                temp.push_back(val);
                
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            
            ans.push_back(temp);
        }
        
        for(int i=1;i<ans.size();i+=2){
            reverse(ans[i]);
        }
        return ans;
    }
};