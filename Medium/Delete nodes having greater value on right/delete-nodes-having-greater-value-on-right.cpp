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
    Node* reverse( Node *head )
    {
        
        Node* prev = NULL;
        Node* tmp = head->next;
        
        while( head != NULL )
        {
            head->next = prev;
            prev = head;
            head = tmp;
            if( tmp )
            {
                tmp = tmp->next;
            }
            else{
                break;
            }
        }
        return prev;
        
    }
    Node *compute(Node *head)
    {
        // your code goes here
        head = reverse(head);
        int maxi = -1;
        Node* tmp = head;
        Node* d =new Node(-1);
        
        
        while( tmp )
        {
            if( maxi <= tmp->data )
            {
                maxi = tmp->data;
                d->next = tmp;
                d = tmp;
            }
            
            tmp = tmp->next;
        }
        
        d->next = NULL;
        
        
        return reverse(head);

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