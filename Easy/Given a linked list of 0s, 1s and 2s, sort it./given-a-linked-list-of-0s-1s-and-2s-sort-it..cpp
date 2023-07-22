//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends

/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) 
    {
        
        // Add code here
        if(!head) return head;
        Node* zerodummy=new Node(0);
        Node* z=zerodummy;
        Node* onedummy=new Node(-1);
        Node* o=onedummy;
        Node* twodummy=new Node(-2);
        Node* t=twodummy;
        Node* curr=head;
        while(curr)
        {
            if(curr->data==0)
            {
                z->next=curr;
                z=curr;
                curr=curr->next;
            }
            else if(curr->data==1)
            {
                o->next=curr;
                o=curr;
                curr=curr->next;
            }
            else
            {
                t->next=curr;
                t=curr;
                curr=curr->next;
            }
        }
        
        if(onedummy->next==NULL and zerodummy->next==NULL and twodummy->next!=NULL)
        {
            t->next=NULL;
            return twodummy->next;
        }
        else if( onedummy->next==NULL and twodummy->next!=NULL and zerodummy->next!=NULL )
        {
            t->next=NULL;
            z->next=twodummy->next; 
            return zerodummy->next;
        }
        else if( onedummy->next!=NULL and twodummy->next==NULL and zerodummy->next!=NULL )
        {
            o->next=NULL;
            z->next=onedummy->next;
            return zerodummy->next;
        }
        else if( onedummy->next!=NULL and twodummy->next!=NULL and zerodummy->next==NULL )
        {
            t->next=NULL;
            o->next=twodummy->next;
            return onedummy->next;
        }
        else if( onedummy->next==NULL and twodummy->next==NULL and zerodummy->next!=NULL )
        {
            z->next=NULL;
            return zerodummy->next;
        }
        else if( onedummy->next!=NULL and twodummy->next==NULL and zerodummy->next==NULL )
        {
            o->next=NULL;
            return onedummy->next;
        }
        else
        {
            z->next=onedummy->next;
            o->next=twodummy->next;
            t->next=NULL;
            return zerodummy->next;
        }
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends