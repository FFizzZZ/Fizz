## Leetcode
```
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        M, s = 0, 0
        for x in nums:
            s += x
            M = max(M, x)
        if m == 1: return s
        
        l, r = M, s
        while l < r:
            mid = (l + r) // 2
            if self.valid(mid, nums, m):
                r = mid
            else:
                l = mid + 1
        return l
    def valid(self, target, nums, m):
        cnt = 1
        total = 0
        for x in nums:
            total += x
            if total > target:
                total = x
                cnt += 1
                if cnt > m:
                    return False
        return True
```
