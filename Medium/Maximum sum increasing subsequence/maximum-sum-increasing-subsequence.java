//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int Arr[] = new int[n];
                    for(int i = 0;i<n;i++)
                        Arr[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.maxSumIS(Arr,n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{
    int max( int a, int b )
    {
        return a>b?a:b;
    }
    public int doo( int arr[], int i, int n, int prev, int dp[][])
    {
        if( i == n )
        {
            return 0;
        }
        
        
        if(dp[i][prev+1] != -1  )
        {
            return dp[i][prev+1];
        }
        
        int p = 0, np = 0;
        
        if( prev == -1 || arr[prev] < arr[i] )
        {
            p = arr[i]+doo(arr,i+1,n,i,dp);
        }
        
        np = doo(arr,i+1,n,prev,dp);
        
        return dp[i][prev+1] = max(p,np);
    }
	public int maxSumIS(int arr[], int n)  
	{  
	    //code here.
	    int dp[][] = new int[n+1][n+1];
	    
	    for( int[] it: dp )
	    {
	        Arrays.fill(it,-1);
	    }
	    
	    return doo(arr,0,n,-1,dp);
	}  
}