//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool ishappy(int n)
    {
        if(n<=9)
        {
            if(n==1 or n==7)
            {
                return true;
            }
            return false;
        }
        int q=0;
        while(n)
        {
            int r=n%10;
            q+=r*r;
            n=n/10;
        }
        return ishappy(q);
    }
    int nextHappy(int n)
    {
        // code here
        while(!ishappy(n+1))
        {
            n++;
        }
        return n+1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends