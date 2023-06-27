//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<string>tmp;
    void doo( int n, string s, int ind)
    {
        if( n == 0 )
        {
            // cout<<s<<endl;
            tmp.push_back(s);
            return;
        }
        
        for( int i = ind; i <= 9; i++ )
        {
            doo(n-1,s+to_string(i),i+1);
        }
        
    }
    vector<int> increasingNumbers(int n)
    {
        // Write Your Code here
        if(n==1)
        doo(n,"",0);
        else
        doo(n,"",1);
        for(auto it:tmp)
        {
            cout<<it<<" ";
        }
        return {};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends