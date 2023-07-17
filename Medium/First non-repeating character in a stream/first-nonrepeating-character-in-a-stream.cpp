//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    
    void remove(char it, queue<char>&q)
    {
        queue<char>temp;
        
        while ( !q.empty() )
        {
            if ( it != q.front() )
            {
                temp.push(q.front());
                q.pop();
            }
            else
            {
                q.pop();
                continue;
            }
            
        }
        q=move(temp);
    }

	string FirstNonRepeating(string s)
	{
	    // Code here
	    unordered_map<char,int>pre;
	    unordered_map<char,int>vis;
	    queue<char>q;
	    
	    string ans = "";
	    
	    
	    for(auto it : s )
	    {
	        if( pre[it] == 0 )
	        {
	            q.push(it);
	            pre[it] = 1;
	            vis[it]++;
	        }
	        else
	        {
	            if( vis[it] )
	            {
	                vis[it]--;
	                remove(it,q);
	            }
	        }
	        
	        if(!q.empty())
	        ans+=q.front();
	        else
	        ans+='#';
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends