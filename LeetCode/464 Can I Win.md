## Leetcode
#### Using tuple
```
class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        if maxChoosableInteger * (maxChoosableInteger + 1) // 2 < desiredTotal:
            return False
        cache = {}
        return self.helper(tuple(range(1, maxChoosableInteger + 1)), desiredTotal, cache)
    def helper(self, nums, desiredTotal, cache):
        if not nums: return False
        if nums in cache: return cache[nums]
        if nums[-1] >= desiredTotal: return True
        for i in range(len(nums)):
            if not self.helper(nums[:i] + nums[i + 1:], desiredTotal - nums[i], cache):
                cache[nums] = True
                return True
        cache[nums] = False
        return False
```
#### Using bits
```
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if (1+maxChoosableInteger)  *maxChoosableInteger // 2 < desiredTotal:
            return False
        return self.f(0, maxChoosableInteger, desiredTotal, {})
    def f(self, selected, m, s, d):
        if selected in d: return d[selected]
        for i in reversed(range(1, m + 1)):
            new = 1 << i
            if selected & new: continue
            if s <= i or not self.f(selected | new, m, s - i, d):
                d[selected] = True
                return True
        d[selected] = False
        return False
```
##### This one is fastest! I think there is some tricks behind it: if you cannot win the game at once, you won't add the largest number to the pool. But I can't figure it out why it works...
```
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if (1+maxChoosableInteger)*maxChoosableInteger//2 < desiredTotal:
            return False   
        memo = {}
        def DFS(current_sum, selected):
            if selected in memo:
                return memo[selected]        
            if current_sum + maxChoosableInteger >= desiredTotal:
                memo[selected] = True    
                return True    
            for n in reversed(range(1, maxChoosableInteger)):
                mask = 1<<n
                if selected & mask:
                    continue
                new_select = selected | mask
                if not DFS(current_sum+n, new_select):
                    memo[selected] = True
                    return True
            memo[selected] = False
            return False
        return DFS(0,1)
```


