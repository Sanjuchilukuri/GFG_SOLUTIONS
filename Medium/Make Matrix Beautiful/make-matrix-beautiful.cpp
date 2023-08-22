//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int max_sum_row = INT_MIN;
        vector<int>row;
        for( int i = 0; i < n; i++ )
        {
            int sum = 0;
            for( int j = 0; j < n; j++ )
            {
                sum+=matrix[i][j];
            }
            row.push_back(sum);
            if( sum > max_sum_row )
            {
                max_sum_row = sum;
            }
        }
        
        
        int max_sum_col = INT_MIN;
        vector<int>col;
        for( int i = 0; i < n; i++ )
        {
            int sum = 0;
            for( int j = 0; j < n; j++ )
            {
                sum+=matrix[j][i];
            }
            col.push_back(sum);
            if( sum > max_sum_col )
            {
                max_sum_col = sum;
            }
        }
        
        if( max_sum_row >= max_sum_col )
        {
            int ans = 0;
            for( auto it : row )
            {
                ans+=max_sum_row-it;
            }
            return ans;
        }
        else
        {
            int ans = 0;
            for( auto it : col )
            {
                ans+=max_sum_col-it;
            }
            return ans;
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
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends