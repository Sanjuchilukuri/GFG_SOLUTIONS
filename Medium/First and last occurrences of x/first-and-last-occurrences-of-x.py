#User function Template for python3


class Solution:
    def find(self, arr, n, x):
        
        # code here
        i=0
        fi=-1
        li=-1
        z=0
        j=n-1
        c=0
        while(i<n and j>=0):
            if arr[i]<x and c==0:
                i+=1
            elif arr[i]==x and c==0:
                fi=i
                c=1
            else:
                i+=1
            if arr[j]>x and z==0:
                j-=1
            elif arr[j]==x and z==0:
                li=j
                z=1
            else:
                j-=1
        if fi>li:
            temp=fi
            fi=li
            li=temp
        return (fi,li)


#{ 
 # Driver Code Starts
t=int(input())
for _ in range(0,t):
    l=list(map(int,input().split()))
    n=l[0]
    x=l[1]
    arr=list(map(int,input().split()))
    ob = Solution()
    ans=ob.find(arr,n,x)
    print(*ans)
# } Driver Code Ends