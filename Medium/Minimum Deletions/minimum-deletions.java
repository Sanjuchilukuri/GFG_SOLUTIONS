//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0){
            String S = read.readLine();

            Solution ob = new Solution();
            
            System.out.println(ob.minimumNumberOfDeletions(S));
        }
    } 
} 
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int max( int a, int b )
    {
        return a>b?a:b;
    }
    static int lcs( String rev, String s, int i, int j, int dp[][])
    {
        if( i == rev.length() || j == s.length() )
        {
            return 0;
        }
        
        if( dp[i][j] != -1 )
        {
            return dp[i][j];
        }
        
        if( rev.charAt(i) == s.charAt(j) )
        {
            return 1+lcs(rev,s,i+1,j+1,dp);
        }
        
        return dp[i][j] = max( lcs(rev,s,i+1,j,dp), lcs(rev,s,i,j+1,dp) );
    }
    static int minimumNumberOfDeletions(String S) 
    {
        //your code here
        int dp[][] = new int[S.length()][S.length()];
        
        for( int[] it : dp )
        {
            Arrays.fill(it,-1);
        }
        String rev = new StringBuffer(S).reverse().toString();
        return S.length()-lcs(rev,S,0,0,dp);
    }
}