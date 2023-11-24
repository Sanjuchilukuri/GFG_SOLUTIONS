//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    long long doo( vector<vector<long long>>&mat, int i , int j )
    {
        if( i >= mat.size() || i < 0 || j < 0 || j >= mat.size() )
        {
            return 0;
        }
        return mat[i][j]%1000000007;
    }
    
    vector<long long> nthRowOfPascalTriangle(int n) 
    {
        // code here
        if( n == 1 )
        {
            return {1};
        }
        
        vector< vector<long long> >mat(n,vector<long long>(n,0));
        
        mat[0][0] = 1;
        
        for( int i = 1; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( j == 0 )
                {
                    mat[i][j] = 1;
                }
                else
                mat[i][j] = ( doo(mat,i-1,j-1) + doo(mat,i-1,j) )%1000000007;
            }
        }
        
        
        
        
        vector<long long>ans;
        for( int i = 0; i < n; i++ )
        {
            if( mat[n-1][i] != 0)
            {
                ans.push_back(mat[n-1][i]);
            }
            else
            break;
        }
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends