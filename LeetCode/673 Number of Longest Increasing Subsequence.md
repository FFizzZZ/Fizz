## Leetcode
#### Dynamic Programming
```
class Solution(object):
    def findNumberOfLIS(self, nums):
        n = len(nums)
        if n <= 1: return n
        tails = [1] * n
        cnt = [1] * n
        for j in range(n):
            for i in range(j):
                if nums[i] < nums[j]:
                    if tails[i] >= tails[j]:
                        tails[j] = tails[i] + 1
                        cnt[j] = cnt[i]
                    elif tails[i] + 1 == tails[j]:
                        cnt[j] += cnt[i]
        length = max(tails)
        return sum(c for i, c in enumerate(cnt) if tails[i] == length)
```
        
        

        
        
        
        
        
   
        
        
                
        
        
        
   
        
        
        
        
        
        
        
        
        
        
        
        
        
        
     
 
