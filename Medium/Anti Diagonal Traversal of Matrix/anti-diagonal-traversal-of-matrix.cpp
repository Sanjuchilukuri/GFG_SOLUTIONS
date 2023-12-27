//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void dfs(int row, int col, int &n, vector<vector<int>> &matrix, vector<int> &ans, vector<vector<int>> &vis) 
    {
        vis[row][col] = 1;
        ans.push_back(matrix[row][col]);
        
        int nrow = row+1;
        int ncol = col-1;
        
        if(nrow < n and nrow >= 0 and ncol < n and ncol >= 0 and vis[nrow][ncol] == 0) {
            dfs(nrow, ncol, n, matrix, ans, vis);
        }
    }
    
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        
        int n = matrix.size();
        vector<int> ans;
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                if(!vis[i][j])
                {
                    dfs(i, j, n, matrix, ans, vis);
                }
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
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends