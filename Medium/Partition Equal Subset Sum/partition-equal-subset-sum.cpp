//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool doo( int arr[], int total,  int sum, int i, int n, vector<vector<int>>&dp )
    {
        // cout<<total<<" "<<sum<<" "<<i<<endl;   
        if( i >= n )
        {
            if( total == sum )
            {
                // cout<<total<<" "<<sum;
                return 1;
            }
            return 0;
        }
        
        if( sum > total )
        {
            return 0;
        }
        
        if( dp[i][total] != -1 )
        {
            return dp[i][total];
        }
        
        int p = doo( arr, total - arr[i], sum+arr[i],  i+1, n, dp);
        int np = doo( arr,  total , sum, i+1, n, dp);
        return dp[i][total] = max(p,np);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total = 0;
        for( int i = 0; i < N; i++ )
        {
            total+=arr[i];
        }
        vector<vector<int>>dp(N+1,vector<int>(total+1,-1));
        return doo( arr, total, 0, 0, N, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends