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
    int position(vector<int> v,int key,int s,int e){
        for(int i=s;i<=e;i++){
            if(v[i]==key){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int& index,int sindex,int eindex){
        if(index>=preorder.size() || sindex>eindex){
            return NULL;
        }
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos=position(inorder,element,sindex,eindex);
        
        root->left=solve(inorder,preorder,index,sindex,pos-1);
        root->right=solve(inorder,preorder,index,pos+1,eindex);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        
        TreeNode* root = solve(inorder,preorder,index,0,preorder.size()-1);
        
        return root;
    }
};