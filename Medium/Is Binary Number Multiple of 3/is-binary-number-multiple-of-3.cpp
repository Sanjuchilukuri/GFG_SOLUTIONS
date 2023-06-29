//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
    public:	
	int isDivisible(string s)
	{
	   long long int oc=0;
	   long long int ec=0;
	   int n=s.size();
	   //cout<<n<<endl;
	   for(int i=0;i<n;i++)
	   {
	       if(i%2==0 and s[i]=='1')
	       {
	           ec++;
	       }
	       else if(s[i]=='1' and i%2!=0)
	       {
	           oc++;
	       }
	   }
	   //cout<<ec<<" "<<oc<<endl;
	   if(abs(ec-oc)%3==0)
	   {
	       return 1;
	   }
	   else
	   {
	       return 0;
	   }
	}
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends