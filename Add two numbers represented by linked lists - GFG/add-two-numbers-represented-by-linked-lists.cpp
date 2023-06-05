//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverse(struct Node* head) {
        struct Node* curr = head ;
        struct Node* prev = nullptr;
        
        while(curr) {
            struct Node* temp = curr->next ;
            curr->next = prev ;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    struct Node* addLists(struct Node* first , struct Node* second , int count) {
        // base case 
        if(first == nullptr && second == nullptr ) {
            if(count == 0) return nullptr;
            struct Node* temp = new Node(count);
            return temp;
        }
        // calculating the sum of digits
        int sum = 0 ;
        // add the number from list 1 only if it exists
        if(first) {
            sum+=first->data;
            first = first->next;
        }
        // add the number from list 2 only if it exists
        if(second) {
            sum+=second->data;
            second = second->next;
        }
        // adding the carry
        sum+=count;
        // calculating the next carry 
        count = sum/10;
        // creating the node with last digit of sum
        struct Node* temp = new Node(sum%10);
        
        // recursive call
        temp -> next = addLists(first , second , count);
        
        return temp;
        
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // reversing the first list
        first = reverse(first);
        // reversing the second list
        second = reverse(second);
        
        int count = 0;
        struct Node* ans = addLists(first , second , count);
        
        // reversing the answer
        ans = reverse(ans);
        
        // reversing the first and second list to recover the original list not necessary
        // reverse(first);
        // reverse(second) ;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends