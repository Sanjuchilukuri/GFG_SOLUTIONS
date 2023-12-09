//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool isprime( int n )
    {
        if( n <= 1 )
        {
            return false;
        }
        
        int sq = (int)sqrt(n)+1;
        
        for( int i = 2; i < sq; i++ )
        {
            if( n % i == 0 )
            {
                return false;
            }
        }
        return true;
    }
    
    int sod( int n )
    {
        int sum = 0;
        while(n)
        {
            int rem = n % 10;
            sum += rem;
            n/=10;
        }
        return sum;
    }
    
    int smithNum(int n) 
    {
        // code here
        if(isprime(n))
        {
            return false;
        }
        vector<int>primes;
        int sum = sod(n);
       
        
        for( int i = 2; i <= (int)sqrt(n); i++ )
        {
            if( n % i == 0 )
            {
                int z = n/i;
                
                if( isprime(i) )
                {
                    primes.push_back(i);
                }
                if( isprime(z) )
                {
                    primes.push_back(z);
                }
            }
        }
        
        // for( auto it : primes )
        // {
        //     cout<<it<<" ";
        // }
        int i = 0;
        while(n>1)
        {
            if( n % primes[i]  == 0 )
            {
                n = n/primes[i];
                sum -= sod(primes[i]);
            }
            else
            {
                i++;
            }
        }
        
        
        if( sum == 0 )return 1;
        return 0;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends