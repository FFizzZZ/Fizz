## Leetcode
```
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        ans = 0
        d = collections.Counter(nums)
        if k > 0:
            for i in d:
                if i + k in d: ans += 1
        elif k == 0:
            for i in d:
                if d[i] > 1: ans += 1
        return ans
```
