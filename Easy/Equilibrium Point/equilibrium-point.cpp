//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return -1;
        }
        int total =0,sum=0;
        for(int i=0;i<n;i++)
        {
            total+=a[i];   //13
        }
        for(int i=0;i<n;i++)
        {
            total-=a[i];//13,13-1=12|12-3=9||9-5==4
            if(total==sum)//12==0|9==1||4==4
            {
                return i+1;
            }
            else
            {
                sum+=a[i];//0+1=1||1+3=4||
            }
        }
        return -1;
    }
        
};


//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends