## Leetcode
```
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        cnt = m = 0
        for i, v in enumerate(arr):
            if v > m:
                m = v
            if m == i:
                cnt += 1
        return cnt
```
