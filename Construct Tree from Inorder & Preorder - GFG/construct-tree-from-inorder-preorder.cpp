// { Driver Code Starts
//

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int position(int in[],int key,int s,int e){
        for(int i=s;i<=e;i++){
            if(in[i]==key){
                return i;
            }
        }
        return -1;
    }
    struct Node* solve(int in[],int pre[],int n,int& prindex,int instart,int inend){
        if(prindex>=n || instart>inend){
            return NULL;
        }
        int element=pre[prindex++];
        struct Node* root =new Node(element);
        
        
        int pos=position(in,element,instart,inend);
        
        root->left=solve(in,pre,n,prindex,instart,pos-1);
        root->right=solve(in,pre,n,prindex,pos+1,inend);
        
        return root;
    }
    
    void postorder(struct Node* root){
        if(root==NULL){
            return;
        }
        
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int index=0;
        struct Node* root = solve(in,pre,n,index,0,n-1);
        
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends