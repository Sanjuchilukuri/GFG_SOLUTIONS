//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    void doo( string &ans, long long int n )
    {
        if( n <= 26 )
        {
            ans+=(n+'@');
            return;
        }
        int rem = n%26;
        if(rem == 0 )
        {
            ans+='Z';
            rem+=1;
        }
        else
        {
            ans+=(rem+'@');
        }
        n-=rem;
        n/=26;
        doo(ans,n);
    }
    string colName (long long int n)
    {
        // your code here
        string ans="";
        doo(ans,n);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends