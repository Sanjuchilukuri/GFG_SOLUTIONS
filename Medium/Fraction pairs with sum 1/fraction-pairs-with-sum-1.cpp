//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int puvu( int n, vector<int>&arr)
    {
        unordered_map<int,int>mp;
        int c = 0;
        for( auto it : arr )
        {
            if( mp[n-it])
            {
                c+=mp[n-it];
            }
            mp[it]++;
        }
        return c;
    }
    int countFractions(int n, int num[], int den[])
    {
        if( n <= 1 )
        {
            return 0;
        }
        
        int ans = 0;
        for( int i = 0; i < n; i++ )
        {
            int k = __gcd(num[i],den[i]);
            num[i] /= k;
            den[i] /= k;
        }
        
        unordered_map<int,vector<int>>mp;
        
        for( int i = 0; i < n; i++ )
        {
            mp[den[i]].push_back(num[i]);
        }
        
       
        for( auto it : mp )
        {
            int k = it.first;
            auto v = it.second;
            ans+=puvu(k,v);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends