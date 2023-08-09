//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool prime( int n )
    {
        if( n <= 1 )
        {
            return false;
        }
        
        int sq = sqrt(n);
        
        for( int i = 2; i <= sq; i++ )
        {
            if( n % i == 0 )
            {
                return false;
            }
        }
        return true;
    }
    long long int largestPrimeFactor(int N)
    {
        // code here
        int sq = sqrt(N);
        vector<int>fro;
        vector<int>bac;
        
        for( int i = 1; i <= sq; i++ )
        {
            if( N % i == 0 )
            {
                fro.push_back(i);
                bac.push_back(N/i);
            }
        }
        
        for( int i = bac.size()-1; i >=0 ; i-- )
        {
            if( prime(bac[i]) )
            {
                return bac[i];
            }
        }
        
        for( int i = fro.size()-1; i >=0 ; i-- )
        {
            if( prime(fro[i]) )
            {
                return fro[i];
            }
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends