//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    
    void doo( Node* present, Node* par, unordered_map< Node*, vector<Node*> >&mp )
    {
        if( present == NULL )
        {
            return;
        }
        
        if( par )
        {
            mp[present].push_back(par);
        }
        if( present->left )
        {
            mp[present].push_back(present->left);
        }
        if( present->right)
        {
            mp[present].push_back(present->right);
        }
        
        doo( present->left, present, mp );
        doo( present->right, present, mp );
    }
    
    void fun(  unordered_map< Node*, vector<Node*> >&mp,  unordered_map< Node*, bool> &vis, Node* target, int k, vector<int>&ans )
    {
        
        if( k == 0 )
        {
           
            ans.push_back(target->data);
            return;
        }
        vis[target] = 1;
        
        for( auto it : mp[target] )
        {
            if( !vis[it] )
            {
                fun(mp,vis,it,k-1,ans);
            }
        }
    }
    
    void find( Node* &tar, int target, Node* root, int &flag )
    {
        if( root == NULL || flag )
        {
            return;
        }
        
        if( root->data == target )
        {
            flag = 1;
            tar = root;
            return;
        }
        
        find( tar, target, root->left, flag);
        find( tar, target, root->right, flag);
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        
        
        unordered_map< Node*, vector<Node*> >mp;
        doo(root,NULL,mp);
        
        
        Node* tar;
        int flag = 0;
        find(tar,target,root,flag);
        
        unordered_map< Node*, bool> vis;
        
       
        vector<int>ans;
        fun(mp,vis,tar,k,ans);
        
       
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends