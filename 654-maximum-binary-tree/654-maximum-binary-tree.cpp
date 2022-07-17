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
    int maxiindex(vector<int>&nums,int i,int j){
        int maxi=INT_MIN;
        int index=i;
        
        for(int k=i;k<j;k++){
            if(nums[k]>maxi){
                maxi=nums[k];
                index=k;
            }
        } 
        return index;
    }
    TreeNode* buildBT(vector<int>&nums,int i,int j){
        if( i==j){
            return NULL;
        }  
        int maxi=maxiindex(nums,i,j);
        TreeNode* temp=new TreeNode(nums[maxi]);
        
        temp->left=buildBT(nums,i,maxi);
        temp->right=buildBT(nums,maxi+1,j);
        
        return temp;
    } 
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=buildBT(nums,0,nums.size());
        return root;
    }
};