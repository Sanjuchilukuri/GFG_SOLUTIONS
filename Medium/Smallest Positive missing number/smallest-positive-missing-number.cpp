//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int find_one( int f, int arr[], int n)
    {
        
        int low = 0;
        int high = n-1;
        
        while( low <= high )
        {
            int mid = ( low + high) / 2;
            
            if( f == arr[mid] )
            {
                return mid;
            }
            else if( arr[mid] > f)
            {
                high = mid - 1;
            }
            else
            {
                low = mid+1;
            }
        }
        return -1;
    }
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        sort(arr,arr+n);
        int ind = find_one(1,arr,n);
        if( ind == -1 )
        {
            return 1;
        }
        else
        {
            // cout<<arr[ind]<<endl;
            for( int i = ind; i < n-1; i++ )
            {
                if( arr[i]+1== arr[i+1] ||  arr[i] == arr[i+1])
                {
                    continue;
                }
                else
                {
                    return arr[i]+1;
                }
            }
        }
        return arr[n-1]+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends