```
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        d = collections.defaultdict(int)
        cnt = 0
        for x in time:
            r = x % 60
            if r == 0:
                cnt += d[0]
                d[0] += 1
            else:
                cnt += d[60 - r]
                d[r] += 1
        return cnt
```

## Leetcode
```
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        d = collections.defaultdict(int)
        cnt = 0
        for x in time:
            cnt += d[-x % 60]
            d[x % 60] += 1
        return cnt
```

```
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        d = collections.defaultdict(int)
        for x in time:
            d[x % 60] += 1
        ans = 0
        for t, cnt in d.items():
            if t == 0 or t == 30:
                ans += cnt * (cnt - 1) // 2
            elif 60 - t in d and 60 - t > t:
                ans += cnt * d[60 - t]
        return ans
```
