//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void inorder(Node*root,unordered_set<int>&st){
    if(root==NULL){
        return;
    }
    
    inorder(root->left,st);
    st.insert(root->data);
    inorder(root->right,st);
}

void solve(Node* root,unordered_set<int>&st,bool& flag){
    if(root==NULL){
        return;
    }
    
    if(root->left==NULL &&  root->right==NULL){
        if(root->data==1){
            if(st.find(root->data+1)!=st.end()){
                flag=true;
                return;
            }
        }
        else{
            if((st.find(root->data-1)!=st.end()) && (st.find(root->data+1)!=st.end())){
                flag=true;
                return;
            }
        }
    }
    
    solve(root->left,st,flag);
    solve(root->right,st,flag);
}
bool isDeadEnd(Node *root)
{
    unordered_set<int>st;
    inorder(root,st);
    bool flag=false;
    solve(root,st,flag);
    
    return flag;
}