//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int doo( int i, int j, string &s1, string &s2,vector<vector<int>>&dp) 
    {
        if( i < 0 || j < 0 || i >= s1.size() || j >= s2.size() )
        {
            return 0;
        }
        
        if( dp[i][j] != -1 )
        {
            return dp[i][j];
        }
        
        if( s1[i] == s2[j] )
        {
            return 1+doo(i+1,j+1,s1,s2,dp);
        }
        
        return dp[i][j] = max( doo(i+1,j,s1,s2,dp) , doo(i,j+1,s1,s2,dp) );
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return doo(0,0,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends