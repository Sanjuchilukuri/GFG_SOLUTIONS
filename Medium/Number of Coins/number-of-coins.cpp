//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int doo( int coins[], int n, int sum, vector<int>&dp )
	{
	    if( sum == 0 )
	    {
	        return 0;
	    }
	    
	    if( dp[sum] != -1 ) return dp[sum];
	    
	    int c = 1e9;
	    for( int i = 0; i < n; i++ )
	    {
	        if( sum >= coins[i] )
	        {
	            c = min( c, 1+doo(coins, n, sum-coins[i], dp ) );
	        }
	    }
	    return dp[sum] = c;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<int>dp(V+1,-1);
	    int ans = doo(coins,M,V,dp);
	    if( ans == 1000000000 )
	    {
	        return -1;
	    }
	    else
	    {
	        return ans;
	    }
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends