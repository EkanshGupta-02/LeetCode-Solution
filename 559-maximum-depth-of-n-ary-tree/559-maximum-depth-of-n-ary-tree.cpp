/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root,int height,int &maxheight){
        if(root==NULL){
            return;
        }
        if(root->children.size()==0){
            maxheight=max(height,maxheight);
            return;
        }
        for(int i=0;i<root->children.size();i++){
            solve(root->children[i],height+1,maxheight);
        }
    }
    int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }
        int maxheight=INT_MIN;
        solve(root,0,maxheight);
        return maxheight+1;
    }
};