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
        
        
        
