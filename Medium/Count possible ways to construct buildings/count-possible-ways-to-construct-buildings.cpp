//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define mod 1000000007
class Solution{
	public:
	int TotalWays(int N)
	{
	    if( N == 0 )
	    {
	        return 1;
	    }
	    if( N == 1 )
	    {
	        return 4;
	    }
	    long long int a = 1;
	    long long int b = 2;
	    long long int c = a+b;
	    N-=1;
	    while(N--)
	    {
	        c = (a+b)%mod;
	        a = b;
	        b = c;
	    }
	    return ( (c%mod) * (c%mod) )%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends