//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
     Node *reverse(Node *head)
    {
        Node *prev=NULL;
        Node *temp=head;
        while(temp!=NULL)
        {
            Node *curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node *head1=reverse(head);
        Node *dummy=new Node(-1);
        Node *res=dummy;
        Node *temp=head1->next;
        res->next=new Node(head1->data);
        res=res->next;
        int x=head1->data;
        while(temp!=NULL)
        {
            if(x<=temp->data)
            {
                x=temp->data;
                res->next=new Node(x);
                res=res->next;
            }
            temp=temp->next;
        }
        Node *final=reverse(dummy->next);
        return final;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends