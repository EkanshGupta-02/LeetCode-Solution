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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>ans;
        
        if(n%2==0)return{};
        if(n==1) return {new TreeNode(0)};
        
        for(int i=1;i<n;i+=2){
            
            auto lst = allPossibleFBT(i);
            auto rst = allPossibleFBT(n-i-1);
            
            for(auto ln:lst){
                for(auto rn:rst){
                    auto newnode = new TreeNode(0,ln,rn);
                    ans.push_back(newnode);
                }
            }
        }
        
        return ans;
    }
};