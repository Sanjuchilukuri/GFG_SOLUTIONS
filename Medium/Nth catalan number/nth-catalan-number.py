from math import *
class Solution:
    
    def find_catalan_number(self,n):
        ans = (factorial(2*n))//(factorial(n+1)*factorial(n))
        return ans % 1000000007;
        
    def findCatalan(self, n : int) -> int:
        # code here
        return self.find_catalan_number(n);
        



#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        obj = Solution()
        res = obj.findCatalan(n)
        
        print(res)
        

# } Driver Code Ends