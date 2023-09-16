//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    const int mod = 1e9+7;
    long long doo( int n, vector<long long>&dp )
    {
        if(  n <= 0 )
        {
            if( n == 0 )
            {
                return 1;
            }
            return 0;
        }
        
        if( dp[n] !=  -1 )
        {
            return dp[n];
        }
        
        long long o = doo( n-1, dp );
        long long t = doo( n-2, dp );
        long long p = doo( n-3, dp );
        
        return dp[n] = ((o+t)%mod+p)%mod;
    }
    
    long long countWays(int n)
    {
        
        // your code here
        vector< long long >dp(n+1,-1);
        return doo( n, dp );
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends