* https://zh.wikipedia.org/wiki/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84
```
class Solution:
    def countSmaller(self, nums):
        rank = {val: i + 1 for i, val in enumerate(sorted(nums))}
        n = len(nums)
        BIT = [0] * (n + 1)
        
        def update(i):
            while i <= n:
                BIT[i] += 1
                i += i & (-i)
        def get(i):
            s = 0
            while i > 0:
                s += BIT[i]
                i -= i & (-i)
            return s
        
        ans = []
        for x in reversed(nums):
            update(rank[x])
            ans += get(rank[x] - 1),
        return ans[::-1]
```
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
     
