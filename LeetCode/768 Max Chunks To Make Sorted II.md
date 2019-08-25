## Leetcode
#### Sliding Window
```
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        d = collections.defaultdict(int)
        cnt = ans = 0
        for x, y in zip(arr, sorted(arr)):
            d[x] += 1
            val = d[x]
            if val == 1: cnt += 1
            elif val == 0: cnt -= 1
            d[y] -= 1
            val = d[y]
            if val == -1: cnt += 1
            elif val == 0: cnt -= 1
            if cnt == 0: ans += 1
        return ans
```
