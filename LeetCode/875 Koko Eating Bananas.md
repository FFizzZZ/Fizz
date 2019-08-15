```
class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        l = math.ceil(sum(piles) / H)
        r = max(piles)
        while l < r:
            mid = (l + r) // 2
            time = sum([math.ceil(x / mid) for x in piles])
            if time <= H:
                r = mid
            else:
                l = mid + 1
        return l
```

## Leetcode
```
class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        def eat_all(K):
            return sum([(p - 1) // K + 1 for p in piles]) <= H 

        if H < len(piles):
            return -1
        elif H == len(piles):
            return max(piles)
        else:
            total = sum(piles)
            lo, hi = math.ceil(total / H), math.ceil((total) / (H - len(piles) + 1))
            while lo < hi:
                mid = (lo + hi) // 2
                if eat_all(mid):
                    hi = mid
                else:
                    lo = mid + 1
            return lo
```
