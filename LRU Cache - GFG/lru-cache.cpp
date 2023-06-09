//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

struct Node{
    int key, data;
    Node* next;
    Node* prev;
    
    Node(int k, int d){
        key=k;
        data=d;
    }
};

class LRUCache
{
    private:
    Node *head=new Node(-1, -1);    
    Node *tail=new Node(-1, -1);
    
    int csize;
    unordered_map<int, Node*> pos;
        
    void addnode(Node *curr){
        Node *temp=head->next;
        curr->next=temp;
        curr->prev=head;
        head->next=curr;
        temp->prev=curr;
    }
    
    void delnode(Node *curr){
        Node *cprev=curr->prev;
        Node *cnext=curr->next;
        cprev->next=cnext;
        cnext->prev=cprev;
    }
    
    public:
    //Initialization of capacity, head, tail.
    LRUCache(int cap){
        csize=cap;
        head->next=tail;
        tail->prev=head;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key){
            //If not present return -1.
        if (pos.find(key)==pos.end()) return -1;
        
        Node *curr=pos[key];
        int val=curr->data;
            // Reposition Node
        delnode(curr);
        addnode(curr);
            //Update hashmap & return value.
        pos[key]=head->next;
        return val;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value){
            //If already present delete node to insert in front.
        if (pos.find(key)!=pos.end()){
            Node *curr=pos[key];
            delnode(curr);
        }
            //If cache is full delete last node.
        else if(pos.size()==csize){
            pos.erase(tail->prev->key);
            delnode(tail->prev);
        }
            //Update the cache with the new key, value pair at front.
        Node* newnode=new Node(key, value);
        addnode(newnode);
        pos[key]=head->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends