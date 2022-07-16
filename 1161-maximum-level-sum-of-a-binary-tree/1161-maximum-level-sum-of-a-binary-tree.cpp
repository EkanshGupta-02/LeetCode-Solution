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
    void solve(TreeNode* root,int& maxsum,int& maxlevel,int& level){
        if(root==NULL){
            return;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                sum += front->val;
                
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            
            level++;
            
            if(sum>maxsum){
                maxsum=sum;
                maxlevel=level;
            }
        }
    }
    int maxLevelSum(TreeNode* root) {
        int maxsum=INT_MIN;
        int maxlevel=0;
        int level=0;
        solve(root,maxsum,maxlevel,level);
        
        return maxlevel;
    }
};