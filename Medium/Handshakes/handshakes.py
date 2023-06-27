#User function Template for python3
from math import *
class Solution:
    def find_catalan_number(self,n):
        ans = (factorial(2*n))//(factorial(n+1)*factorial(n))
        return ans;
    def count(self, N):
        # code here
        n = N//2;
        
        return self.find_catalan_number(n);


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        ob = Solution()
        print(ob.count(N))
# } Driver Code Ends