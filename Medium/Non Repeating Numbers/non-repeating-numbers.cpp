//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int ans=0;
        int j=1;
        for(auto it:nums)
        {
            ans^=it;
        }
        
        while(ans)
        {
            if(ans&1)
            {
                break;
            }
            ans>>=1;
            j<<=1;
        }
        int lx=0,rx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&j)
            {
                lx^=nums[i];
            }
            else
            {
                rx^=nums[i];
            }
        }
        if(lx>rx)
        {
            swap(lx,rx);
        }
        return {lx,rx};
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends