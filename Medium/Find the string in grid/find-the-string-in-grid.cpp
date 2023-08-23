//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    bool dfs( int direc, int i, int j, vector<vector<char>>&grid, string word, int k )
    {
        if( i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || word[k] != grid[i][j])
        {
            return false;
        }
        
        if( word.size()-1 == k && word[k] == grid[i][j] )
        {
            return true;
        }
        
        if( direc == 1 ) return dfs( 1, i,   j+1, grid, word, k+1 );
        if( direc == 2 ) return dfs( 2, i+1, j+1, grid, word, k+1 );
        if( direc == 3 ) return dfs( 3, i+1, j,   grid, word, k+1 );
        if( direc == 4 ) return dfs( 4, i+1, j-1, grid, word, k+1 );
        if( direc == 5 ) return dfs( 5, i,   j-1, grid, word, k+1 );
        if( direc == 6 ) return dfs( 6, i-1, j-1, grid, word, k+1 );
        if( direc == 7 ) return dfs( 7, i-1, j,   grid, word, k+1 );
        if( direc == 8 ) return dfs( 8, i-1, j+1, grid, word, k+1 );
        
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector< vector<int> >ans;
	    
	    for( int i = 0; i < n; i++ )
	    {
	        for( int j = 0; j < m; j++ )
	        {
	            if( word[0] == grid[i][j] )
	            {
	                for( int d = 1; d <= 8; d++ )
	                {
	                    if( dfs( d, i, j, grid, word, 0) )
	                    {
	                        ans.push_back({i,j});
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends