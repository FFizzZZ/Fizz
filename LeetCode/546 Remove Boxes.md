## Leetcode
```
class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        n = len(boxes)
        memo = dict()
        def dp(i, j, k):
            if i > j: return 0
            if (i, j, k) in memo: return memo[i, j, k]
            m = i
            while m + 1 <= j and boxes[m + 1] == boxes[i]:
                m += 1
            i, k = m, k + m - i
            ans = dp(i + 1, j, 0) + (k + 1) ** 2
            for m in range(i + 1, j + 1):
                if boxes[i] == boxes[m]:
                    tmp = dp(i + 1, m - 1, 0) + dp(m, j, k + 1)
                    if tmp > ans: ans = tmp
            memo[i, j, k] = ans
            return ans
        return dp(0, n - 1, 0)
```
#### FASTEST
##### Use dict() to record the index of boxes with the same color
```
from functools import lru_cache
class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        pre = [-1] * len(boxes)
        d = dict()
        for idx, val in enumerate(boxes):
            if val not in d:
                d[val] = idx
            else:
                pre[idx] = d[val]
                d[val] = idx
        @lru_cache(maxsize = None)
        def dp(i, j, k):
            if i > j: return 0
            while i < j and boxes[j] == boxes[j - 1]:
                j -= 1
                k += 1
            ans = (k + 1) ** 2 + dp(i, j - 1, 0)
            t = pre[j]
            while t >= i:
                tmp = dp(t + 1, j - 1, 0) + dp(i, t, k + 1)
                if tmp > ans: ans = tmp
                t = pre[t]
            return ans
        return dp(0, len(boxes) - 1, 0)
```
