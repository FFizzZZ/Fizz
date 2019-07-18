```
class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        if maxChoosableInteger * (maxChoosableInteger + 1) // 2 < desiredTotal:
            return False
        cache = {}
        
        def helper(nums, desiredTotal):
            if not nums: return False
            if nums in cache: return cache[nums]
            if nums[-1] >= desiredTotal: return True
            for i in range(len(nums)):
                if not helper(nums[:i] + nums[i + 1:], desiredTotal - nums[i]):
                    cache[nums] = True
                    return True
            cache[nums] = False
            return False
        
        return helper(tuple(range(1, maxChoosableInteger + 1)), desiredTotal)
```
