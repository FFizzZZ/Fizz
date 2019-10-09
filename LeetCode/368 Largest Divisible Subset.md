## Leetcode
#### Dynamic Programming
```
class Solution:
    def largestDivisibleSubset(self, nums):
        dp = {-1: []}
        for x in sorted(nums):
            dp[x] = max([dp[key] for key in dp if x % key == 0], key = len) + [x]
        return max(dp.values(), key = len)
```

```
class Solution:
    def largestDivisibleSubset(self, nums):
        if not nums: return []
        dp = dict()
        for x in sorted(nums):
            new = []
            for key in dp:
                if x % key == 0 and len(dp[key]) > len(new):
                    new = dp[key]
            dp[x] = new + [x]
        return max(dp.values(), key = len)
```
        
        
        
        
        
        
        
        
        

