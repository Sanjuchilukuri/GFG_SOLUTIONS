//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int ind = 0;
    int flag = 0;
    
    void doo(  int a[MAX][MAX], int r_s, int r_e, int c_s, int c_e, int k)
    {
        if( r_e < r_s || c_e < c_s || flag || k == 0 )
        {
            return;
        }
        
        for( int i = r_s; i <= c_e; i++ )
        {
            if( k > 0 )
            {
                --k;
            }
            if( k == 0)
            {
                ind = a[r_s][i];
                flag = 1;
                k--;
            }
            else if( k < 0 )
            {
                break;
            }
            // cout<<a[r_s][i]<<"-"<<k<<endl;
        }
        
        for( int i = c_s+1; i <= r_e; i++ )
        {
            if( k > 0 )
            {
                --k;
            }
            if( k == 0)
            {
                // cout<<ind<<" ";
                ind = a[i][c_e];
                flag = 1;
                k--;
            }
            else if( k < 0 )
            {
                break;
            }
            // cout<<a[i][c_e]<<"-"<<k<<endl;
        }
        
        
        if( c_e != c_s )
        {
            for( int i = c_e-1; i >= c_s ; i-- )
            {
                if( k > 0 )
                {
                    k--;
                }
                if( k == 0)
                {
                    ind = a[r_e][i];
                    flag = 1;
                    k--;
                }
                else if( k < 0 )
                {
                    break;
                }
                // cout<<a[r_e][i]<<"-"<<k<<endl;
            }
            
        }
        
        
        if( r_e != r_s )
        {
            for( int i = r_e-1; i > r_s ; i-- )
            {
                if( k > 0 )
                {
                    k--;
                }
                if( k == 0)
                {
                    ind = a[i][c_s];
                    flag = 1;
                    k--;
                }
                else if( k < 0 )
                {
                    break;
                }
                // cout<<a[i][c_s]<<"-"<<k<<endl;
            }
            
        }
        
        doo( a, r_s+1, r_e-1, c_s+1, c_e-1, k );
    }
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int r_s = 0, c_s = 0, r_e = n-1, c_e = m-1;
 		doo( a, r_s, r_e, c_s, c_e, k );
 		return ind;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends