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
#### Using bits FASTEST!
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



```
class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        if maxChoosableInteger * (maxChoosableInteger + 1) // 2 < desiredTotal:
            return False
        cache = {}
        return self.helper(1, maxChoosableInteger, desiredTotal, cache)
    def helper(self, selected, maxChoosableInteger, desiredTotal, cache):
        if desiredTotal <= 0: 
            cache[selected] = True
            return True
        if selected in cache: return cache[selected]
        for i in range(1, maxChoosableInteger):
            new = 1 << i
            if new & selected: continue
            if not self.helper(new | selected, maxChoosableInteger, desiredTotal - i, cache):
                cache[selected] = True
                return True
        cache[selected] = False
        return False
```
