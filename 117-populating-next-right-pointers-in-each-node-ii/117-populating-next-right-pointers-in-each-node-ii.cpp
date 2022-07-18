/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* find_next(Node* root){
        if(root==NULL){
            return NULL;
        }
        
        while(root && !root->left && !root->right){
            root=root->next;
        }
        
        if(root) return root->left?root->left:root->right;
        else return NULL;
    }
    void solve(Node* root){
        if(root==NULL){
            return;
        }
        
        if(root->left){
            if(root->right) root->left->next=root->right;
            else root->left->next=find_next(root->next);
        }
        
        if(root->right){
             root->right->next=find_next(root->next);
        }
        solve(root->right);
        solve(root->left);
    }
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};