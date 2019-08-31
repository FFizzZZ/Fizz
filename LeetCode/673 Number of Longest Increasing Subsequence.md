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
        
```
from bisect import bisect_left
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        min_end = [float('inf') for _ in nums]
        count = [0 for _ in nums]
        candi = [[] for _ in nums]
        for n in nums:
            i = bisect_left(min_end, n)
            min_end[i] = n
            if i > 0:
                while candi[i - 1][0][0] >= n:
                    count[i - 1] -= candi[i - 1].pop(0)[1]
                count_e = count[i - 1]
            else:
                count_e = 1
            count[i] += count_e
            candi[i].append((n, count_e))
        # print(count)
        for i in range(len(nums) - 1, -1, -1):
            if count[i] > 0:
                return count[i]
        return 0
```
        
        
        
        
   
        
        
                
        
        
        
   
        
        
        
        
        
        
        
        
        
        
        
        
        
        
     
 
