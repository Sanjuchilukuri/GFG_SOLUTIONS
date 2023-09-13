//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod = 1000000007;
	int doo( int arr[], int i, int n, int sum, vector<vector<int>>&dp )
	{
	    if( i >= n )
	    {
	        if( sum == 0)
	        {
	            return 1;
	        }
	        return 0;
	    }
	    
	   // if( sum == 0 )
	   // {
	   //     return 1;
	   // }
	    
	    if( dp[i][sum] != -1 )
	    {
	        return dp[i][sum];
	    }
	    
	    int p = 0, np = 0;
	    if( sum >= arr[i] )
	    {
	        p = doo(arr,i+1,n,sum-arr[i],dp);
	    }
	    np = doo(arr,i+1,n,sum,dp);
	    
	   // cout<<p<<" "<<np<<endl;
	    
	    return dp[i][sum] = (p+np)%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // vector<int>dp(sum+1,-1);
        int total = 0;
        for( int i = 0; i < n; i++ )
        {
            total+=arr[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return doo(arr,0,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends