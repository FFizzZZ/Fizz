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
