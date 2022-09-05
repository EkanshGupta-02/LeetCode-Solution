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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                Node* front = q.front();
                q.pop();
                
                temp.push_back(front->val);
                
                for(int i=0;i<front->children.size();i++){
                    if(front->children[i]){
                        q.push(front->children[i]);
                    }
                }
            }
            res.push_back(temp);
        }
        
        return res;
    }
};