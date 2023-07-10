//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int doo(int start,vector<int>gas,vector<int>cost)
    {
        int sum=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            int d=(i+start)%n;
            sum+=gas[d]-cost[d];
            if(sum<0)
            {
                return d;
            }
        }
        return -1;
    }
    int tour(petrolPump p[],int n)
    {
       //Your code here
        vector<int>gas;
        vector<int>cost;
        
        for( int i = 0; i < n; i++ )
        {
            gas.push_back(p[i].petrol);
            cost.push_back(p[i].distance);
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            int s=doo(i,gas,cost);
            if(s==-1)
            {
                return i;
            }
            else if(s>i)
            {
                i=s;
            }
            else if( s < i )
            {
                break;
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends