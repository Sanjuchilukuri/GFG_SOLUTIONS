//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int>dp;
    int doo( int n )
    {
        if( n <= 1)
        {
            return n;
        }
        
        if( dp[n] != -1 )
        {
            return dp[n];
        }
        return dp[n] = (doo(n-1) + doo(n-2))%1000000007;
    }
    int nthFibonacci(int n)
    {
      dp = vector<int>(n+1,-1);
      return doo(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends