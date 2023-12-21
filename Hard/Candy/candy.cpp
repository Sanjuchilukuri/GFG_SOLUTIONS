//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &arr) 
    {
        // code here
        int c=1; 
        vector<int>v;
        for(int i=1;i<n;i++)
        {
            v.push_back(c);
            if(arr[i-1]<arr[i])
            {
                c++;
            }
            else
            {
                c=1;
            }
        }
        v.push_back(c);
        
        int c2=1;
        vector<int>rv;
        for(int i=n-1;i>0;i--)
        {
            rv.push_back(c2);
            if(arr[i-1]>arr[i])
            {
                c2++;
            }
            else
            {
                c2=1;
            }
        }
        rv.push_back(c2);
        reverse(rv.begin(),rv.end());
        long mans=0;
        for(int i=0;i<v.size();i++)
        {
            
            mans+=max(v[i],rv[i]);
        }
        
        return mans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends