## Leetcode
```
class Solution(object):
    def maxProduct(self, nums):
        ans = nums[0]
        imax, imin = 1, 1
        for v in nums:
            if v < 0:
                imax, imin = imin, imax
            imax = v if v > v * imax else v * imax
            imin = v if v < v * imin else v * imin
            if imax > ans:
                ans = imax
        return ans
```

```
class Solution(object):
    def maxProduct(self, A):
        B = A[::-1]
        for i in range(1, len(A)):
            A[i] *= A[i - 1] or 1
            B[i] *= B[i - 1] or 1
        return max(A + B)            
```
        
        

        
        
                
        
        


        
