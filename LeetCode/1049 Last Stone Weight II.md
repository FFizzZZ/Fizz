## Leetcode

```
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        dp = {0}
        total = sum(stones)
        for x in stones:
            dp |= {x + i for i in dp}
        return min(abs(total - 2 * i) for i in dp)
```

```
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        dp = {0}
        for x in stones:
            dp = {x + i for i in dp} | {-x + i for i in dp}
        return min(abs(x) for x in dp)
```

```
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        stones.sort(reverse = True)
        total = sum(stones)
        half = total // 2
        self.diff = total + 1
        self.stop = False
        def dfs(idx, left, right):
            if self.stop: return
            if left > half:
                self.diff = min(self.diff, 2 * left - total)
                return
            elif right > half:
                self.diff = min(self.diff, 2 * right - total)
                return
            elif left == half or right == half:
                self.stop = True
                return
            dfs(idx + 1, left + stones[idx], right)
            dfs(idx + 1, left, right + stones[idx])
        dfs(0, 0, 0)
        return total % 2 if self.stop else self.diff
```
