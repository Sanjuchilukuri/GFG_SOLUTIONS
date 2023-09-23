//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n)
    {
     vector<int> ans;
    
     for(int i=0;i<n;i++) 
        arr[i]++;
       
       for(int i=0;i<n;i++){
           
           int idx = arr[i] <= n ? abs(arr[i]) - 1 : arr[i] - n - 1 ;
           
           if(arr[idx]<0){
               arr[idx] = n + abs(arr[idx]);
           }else if(arr[idx]<=n){
               arr[idx] = -arr[idx];
           }
       }
       
       for(int i=0;i<n;i++){
           if(arr[i]>n) ans.push_back(i);
       }
       
       if(ans.size()!=0) return ans;
       else return {-1};
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends