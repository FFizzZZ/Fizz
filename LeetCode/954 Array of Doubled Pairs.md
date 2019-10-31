## Leetcode

```
class Solution:
    def canReorderDoubled(self, A: List[int]) -> bool:
        d = collections.Counter(A)
        for x in sorted(A, key = abs):
            if d[x] == 0: continue
            if d[2 * x] == 0: return False
            d[x] -= 1
            d[2 * x] -= 1
        return True
```

```
class Solution:
    def canReorderDoubled(self, A: List[int]) -> bool:
        d = collections.Counter(A)
        for x in sorted(d, key = abs):
            if d[x] == 0:
                continue
            if d[x] > d[2 * x]:
                return False
            else:
                d[2 * x] -= d[x]
        return True
```
