//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        void find( Node* root, int n, vector<Node*>&v)
        {
            // cout<<root->data<<endl;
            if( root == NULL )
            {
                return ;
            }
            
            if( root->data == n )
            {
                v.push_back(root);
                return;
            }
            
            if( root->data > n )
            {
                v.push_back(root);
                find( root-> left, n, v );
            }
            else
            {
                v.push_back(root);
                find( root-> right, n, v );
            }
            
        }
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            vector<Node*>one;
            vector<Node*>two;
            
            find(root,n1,one);
            find(root,n2,two);
            
            
            // for(auto it: one)
            // {
            //     cout<<it<<" ";
            // }
            
            // cout<<endl;
            
            // for( auto it: two )
            // {
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            
            int i = 0;
            int j = 0;
            Node* ans ;
            while( i < one.size() && j < two.size() )
            {
                if( one[i] == two[j] )
                {
                    // cout<<one[i]->data<<" "<<two[j]->data<<endl;
                    ans = one[i];
                    // cout<<ans->data<<endl;
                    i++;
                    j++;
                }
                else
                {
                    break;
                }
            }
            
            // cout<<ans->data<<" ";
            return ans;
            
        }

};


//{ Driver Code Starts.

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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends