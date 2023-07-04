//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int fun(int n)
    {
        int ans = ( n*(n+1) )/2;
        return ans;
    }
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) 
    {
        // int i = 0;
        // int j = -1;
        // int ans = 1;
        // int flag = 0;
        // int spaces = 0;
        // int c = 0;
        
        // while( i < n && j < n )
        // {
        //     // cout<<ans<<endl;
        //     if( k > ans*a[j+1])
        //     {
        //         ans *= a[j+1];
        //         j++;
        //         flag = 1;
        //     }
        //     else
        //     {
        //         if(flag)
        //         {
        //             flag = 0;
        //             c+=fun(j-i+1) - fun(spaces);
        //             spaces = j-i+1;
        //             ans = ans/a[i];
        //             i++;
        //             spaces--;
        //         }
        //         else
        //         {
        //             ans = ans/a[i];
        //             if(ans==0)
        //             {
        //                 ans = 1;
        //             }
        //             i++;
        //             spaces--;
        //         }
        //         if( i > j && i - j >= 2 )
        //         {
        //             j++;
        //         }
        //     }
            
        // }
        // // cout<<c<<" "<<j<<" "<<i<<endl;
        // if(flag)
        // c+=fun(j-i) - fun(spaces);
        
        // return abs(c);
        long long c=0;
        for(long long i=0;i<n;i++)
        {
            long long s=1;
            for(long long j=i;j<n;j++)
            {
                s*=a[j];
                if(s<k)c+=1;
                else
                break;
            }
        }
        return c;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends