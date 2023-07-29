//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* prev=NULL, *curr=head, *nextt = NULL;
        while(curr)
        {
            nextt = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nextt;
        }
        return prev;
    }
    
    void reorderList(Node* head)
    {
        if(!head || !head->next || !head->next->next)
            return;
        Node *s = head;
        Node *f = head;
        while(f && f->next)
        {
            s = s->next;
            f = f->next->next;
        }
        s->next = reverse(s->next);
        f = s->next;
        s->next = NULL;
        s = head;
        Node* temp;
        while(f)
        {
            temp = s->next;
            s->next = f;
            f = f->next;
            s->next->next = temp;
            s = s->next->next;
        }
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends