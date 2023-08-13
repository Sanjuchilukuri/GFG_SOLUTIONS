//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool it_is_palindrome(string str, int i, int j )
    {
        
        
        while( i < j )
        {
            if( str[i] != str[j] )
            {
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    int addMinChar(string str)
    {    
        //code her
        
        if( it_is_palindrome( str, 0 , str.size()-1 ) )
        {
            return 0;
        }
        
        int i = 0;
        int j = str.size()-1;
        int c = 0;
        
        while( i < j )
        {
            if( str[i] != str[j] )
            {
                c++;
                j--;
            }
            else
            {
                if( it_is_palindrome( str, i, j ) )
                {
                    return c;
                }
                else
                {
                    c++;
                    j--;
                }
            }
        }
        
        return c;
        
    }
};


//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends