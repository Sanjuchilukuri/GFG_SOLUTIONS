//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs( int i, int j, int n, int m, vector<vector<char>>&mat, vector<vector<char>>&chk, vector<vector<int>>&vis )
    {
        if( i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || mat[i][j] == 'X' )
        {
            return;
        }
        chk[i][j] = 'O';
        vis[i][j] = 1;
        
        dfs( i,   j+1, n, m, mat, chk, vis );
        dfs( i,   j-1, n, m, mat, chk, vis );
        dfs( i+1, j,   n, m, mat, chk, vis );
        dfs( i-1, j,   n, m, mat, chk, vis );
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>>chk(n,vector<char>(m,'X'));
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                if( i == 0 || i == n-1 || j == 0 || j == m-1 )
                {
                    if( mat[i][j] == 'O' && chk[i][j] == 'X' )
                    {
                        dfs( i, j, n, m, mat, chk, vis );
                    }
                }
            }
        }
        return chk;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends