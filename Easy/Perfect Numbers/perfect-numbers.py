#User function Template for python3
from math import *
class Solution:
    def isPerfectNumber(self, N):
        # code here 
        if(N==1):
            return 0
        r=1
        sq=int(sqrt(N))
        for i in range(2,sq+1):
            if(N%i==0):
                z=N//i
                r=r+z+i
        if(r==N):
            return 1
        else:
            return 0




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        print(ob.isPerfectNumber(N))
# } Driver Code Ends