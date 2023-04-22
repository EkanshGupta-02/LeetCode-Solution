//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
    public:
    void Parent(Node* root,unordered_map<Node*,Node*>&mp,unordered_map<Node*,int>&vis){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            vis[curr] = 0;
            q.pop();
            
            if(curr->left){
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    int ladoos(Node* root, int home, int k)
    {
        
        unordered_map<Node*,Node*>mp;
        unordered_map<Node*,int>vis;
        Parent(root,mp,vis);
        
        queue<pair<Node*,int>>q;
        // find Node of home node
        for(auto it:mp){
            if(it.second->data==home || it.first->data==home){
                if(it.second->data==home){
                    q.push({it.second,0});
                    break;
                }
                if(it.first->data==home){
                    q.push({it.first,0});
                    break;
                }
                
                
            }
        }
        
        // finding SUM
        
        vis[q.front().first]=1;
        int sum = q.front().first->data;
        while(!q.empty()){
            int lvl = q.front().second;
            int size = q.size();
            if(lvl==k) break;
            lvl++;
            for(int i=0;i<size;i++){
                auto it = q.front();
                Node* curr = it.first;
                q.pop();
                if(curr->left && vis[curr->left]==0){
                vis[curr->left] = 1;
                sum+=curr->left->data;
                q.push({curr->left,lvl});
                }
                
                if(curr->right && vis[curr->right]==0){
                    vis[curr->right] = 1;
                    sum+=curr->right->data;
                    q.push({curr->right,lvl});
                }
                
                if(mp[curr] && vis[mp[curr]]==0){
                    vis[mp[curr]] = 1;
                    sum+=mp[curr]->data;
                    q.push({mp[curr],lvl});
                }
            }
        }
        return sum;

    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends