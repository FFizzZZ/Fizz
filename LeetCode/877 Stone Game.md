```
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return self.f(0, len(piles) - 1, piles, {}) > 0
    def f(self, l, r, piles, d):
        if l > r: return 0
        if (l, r) in d: return d[(l, r)]
        a = piles[l] - self.f(l + 1, r, piles, d)
        b = piles[r] - self.f(l, r - 1, piles, d)
        ans = max(a, b)
        d[(l, r)] = ans
        return ans
```

## Leetcode
```
from functools import lru_cache
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        @lru_cache(None)
        def f(l, r):
            if l > r: return 0
            a = piles[l] - f(l + 1, r)
            b = piles[r] - f(l, r - 1)
            ans = max(a, b)
            return ans
        return f(0, len(piles) - 1) > 0
```
#### Math
```
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return True
```
