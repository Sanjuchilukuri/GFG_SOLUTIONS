//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    bool check( int i, int j, int n, int m )
    {
        if( i < 0 || j < 0 || i >= n || j >= m )
        {
            return false;
        }
        return true;
    }
    int doo( vector<vector<int>>&mat, int i, int j, int n, int m )
    {
        int c = 0;
        
        if( check(i-1,j,n,m) )
        {
            if( mat[i-1][j] == 0 )
            {
                c++;
            }
        }
        
        if( check(i-1,j+1,n,m) )
        {
            if( mat[i-1][j+1] == 0 )
            {
                c++;
            }
        }
        
        if( check(i,j+1,n,m) )
        {
            if( mat[i][j+1] == 0 )
            {
                c++;
            }
        }
        
        if( check(i+1,j+1,n,m) )
        {
            if( mat[i+1][j+1] == 0 )
            {
                c++;
            }
        }
        
        if( check(i+1,j,n,m) )
        {
            if( mat[i+1][j] == 0 )
            {
                c++;
            }
        }
        
        if( check(i+1,j-1,n,m) )
        {
            if( mat[i+1][j-1] == 0 )
            {
                c++;
            }
        }
        
        if( check(i,j-1,n,m) )
        {
            if( mat[i][j-1] == 0 )
            {
                c++;
            }
        }
        
        if( check(i-1,j-1,n,m) )
        {
            if( mat[i-1][j-1] == 0 )
            {
                c++;
            }
        }
        
        if( c%2 == 0 && c != 0 )
        {
            return 1;
        }
        
        return 0;
    }
    int Count(vector<vector<int> >& matrix) 
    {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        int c = 0;
        
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                if( matrix[i][j] == 1)
                {
                    c+=doo(matrix,i,j,n,m);
                }
            }
        }
        
        return c;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends