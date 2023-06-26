//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
public:
        bool flag = false;
    void dfs( string word, vector<vector<char>>& board, int i, int j, int n, int m, int k, vector<vector<int>>&vis )
    {
        
        if( k == word.size())
        {
            flag = true;
            return;
        }
        if( i >= m || j >= n ||  i < 0 || j < 0    || word[k] != board[i][j]  || vis[i][j] == 1 || flag == true)
        {
            return;
        }
        vis[i][j]=1;
        dfs( word, board, i, j+1, n, m, k+1, vis );
        dfs( word, board, i+1, j, n, m, k+1, vis );
        dfs( word, board, i, j-1, n, m, k+1, vis );
        dfs( word, board, i-1, j, n, m, k+1, vis );
        vis[i][j]=0;
    }
    bool wordSearch(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        int k = 0;
        
        for(int i = 0; i < m; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( word[k] == board[i][j] )
                {
                    vector<vector<int>>vis(m,vector<int>(n,0));
                   
                    dfs( word, board, i, j, n, m, k, vis );
                    if( flag )
                    {
                        return true;
                    }
                }
            }
        }
        return false;    
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> mat(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        string str; cin>>str;
        Solution ob;
        auto ans=ob.wordSearch(mat,str);
        cout<<ans<<"\n";
    }
    return 0;
}

// } Driver Code Ends