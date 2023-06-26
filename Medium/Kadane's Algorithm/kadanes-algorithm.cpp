//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        
        // Your code here
        long long int res=0;
        long long int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            res+=arr[i];
            if(ans<res)
            {
                ans=res;
            }
            if(res<=0)
            {
                res=0;
            }
        }
        if(ans==0)
        {
            return -1;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends