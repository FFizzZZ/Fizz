## Leetcode
```
class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        n = len(boxes)
        memo = dict()
        def dp(i, j, k):
            if i > j: return 0
            if (i, j, k) in memo: return memo[i, j, k]
            m = i
            while m + 1 <= j and boxes[m + 1] == boxes[i]:
                m += 1
            i, k = m, k + m - i
            ans = dp(i + 1, j, 0) + (k + 1) ** 2
            for m in range(i + 1, j + 1):
                if boxes[i] == boxes[m]:
                    tmp = dp(i + 1, m - 1, 0) + dp(m, j, k + 1)
                    if tmp > ans: ans = tmp
            memo[i, j, k] = ans
            return ans
        return dp(0, n - 1, 0)
```
        
        
        
        
        
        
        
        
        
        
      
        
```
import functools

class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        
        pre = [-1] * len(boxes)
        cache = {}
        for i, b in enumerate(boxes):
            if b not in cache: cache[b] = i
            else: 
                pre[i] = cache[b]
                cache[b] = i
        
        @functools.lru_cache(None)
        def helper(i, j, k):
            if j < i:
                return 0
            
            while i < j and boxes[j] == boxes[j - 1]:
                j -= 1
                k += 1
            temp = (1 + k) ** 2 + helper(i, j - 1, 0)
            
            t = pre[j]
            while t >= i:
                # 最核心的部分，就是第二个helper的使用。太震撼了。
                temp = max(temp, helper(t + 1, j - 1, 0) + helper(i, t, k + 1))
                t = pre[t]
            return temp

        return helper(0, len(boxes) - 1, 0)
```
