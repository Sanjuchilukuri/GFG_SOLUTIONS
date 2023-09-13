//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int sp)
    {
        // code here

        if( n*9 < sp  || ( sp == 0  && n > 1)  )
        {
            return "-1";
        }
        
        int add = sp/9;
        int empty = n - add;
        int rem = sp%9;
        
        string s;
        
        while( add-- )
        {
            s+="9";
        }
        
        if( rem )
        {
            s+=to_string(rem);
            empty--;
        }
        
        while( empty-- )
        {
            s+="0";
        }
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends