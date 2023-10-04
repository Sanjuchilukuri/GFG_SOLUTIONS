//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) 
    {
        // code here
        int ans = 0;


        map<char,int>mp;
        mp.insert( {'I',1} );
        mp.insert( {'V',5} );
        mp.insert( {'X',10} );
        mp.insert( {'L',50} );
        mp.insert( {'C',100} );
        mp.insert( {'D',500} );
        mp.insert( {'M',1000} );

        ans+=mp[ s[s.size()-1] ];
        for( int it = s.size() - 2; it >= 0; it-- )
        {
           if( mp[ s[it] ] < mp[ s[it+1] ] )
           {
               ans-=mp[ s[it] ];
           }
           else
           {
               ans+=mp[ s[it] ];
           }
        }    
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends