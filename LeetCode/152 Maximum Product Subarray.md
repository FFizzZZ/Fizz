## Leetcode
```
class Solution(object):
    def maxProduct(self, nums):
        ans = nums[0]
        imax, imin = ans, ans
        for v in nums[1:]:
            if v < 0:
                imax, imin = imin, imax
            imax = v if v > v * imax else v * imax
            imin = v if v < v * imin else v * imin
            if imax > ans:
                ans = imax
        return ans
```
        
        
        
