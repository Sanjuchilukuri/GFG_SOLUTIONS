#User function Template for python3

# arr[] : int input array of integers
# k : the quadruple sum required
class Solution:
    def fourSum(self, nums, target):
        n = len(nums)
        if n < 4:
            return []
        
        nums.sort()
        l=[]
        for a in range(len(nums)-3):
            if a > 0 and nums[a] == nums[a - 1]:
                continue
            for b in range(a+1,len(nums)-2):
                if b > a+1 and nums[b] == nums[b - 1]:
                    continue
                c=b+1
                d=len(nums)-1
                while(c<d):
                    if(nums[a]+nums[b]+nums[c]+nums[d]==target):
                        l.append((nums[a],nums[b],nums[c],nums[d]))
                        while c<d and nums[c] == nums[c+1]:
                            c+=1
                        while c<d and nums[d] == nums[d-1]:
                            d-=1
                        c+=1
                        d-=1
                    elif(nums[c]+nums[d]+nums[a]+nums[b]>target):
                        d-=1
                    else:
                        c+=1
       
        return l

#{ 
 # Driver Code Starts
#Initial Template for Python 3


#Main
if __name__=='__main__':
    t = int(input())
    while t:
        t-=1
        n, k=map(int,input().split())
        # print(n, k)
        a=list(map(int,input().strip().split()))[:n]
        # print(a)
        ob=Solution()
        ans=ob.fourSum(a, k)
        # print(ans)
        for v in ans:
            for u in v:
                print(u, end=" ")
            print("$", end="")
        if(len(ans)==0):
            print(-1, end="")
        print()
        
        

# } Driver Code Ends