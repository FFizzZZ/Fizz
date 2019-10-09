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
        
        
        
        
        
        
        
        
        

