//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void doo( int i, int j, int n, int m, vector<vector<int>>&grid)
    {
        if( i < 0 || j < 0 || i >= n || j >=m || grid[i][j] ==0 )
        {
            return;
        }
        grid[i][j] = 0;
        doo( i, j+1, n, m, grid);
        doo( i+1, j, n, m, grid);
        doo( i, j-1, n, m, grid);
        doo( i-1, j, n, m, grid);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) 
    {
        // Code here
        int c = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                if( grid[i][j] and( i == 0 || j == 0 || i == n-1 || j == m-1))
                {
                    doo(i,j,n,m,grid);
                }
            }
        }
        
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                if( grid[i][j] )
                {
                    c++;
                }
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends