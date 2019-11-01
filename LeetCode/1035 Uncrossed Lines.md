

## Leetcode

#### Dynamic Programming
```
class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        m, n = len(A), len(B)
        dp = [0] * (n + 1)
        for i in range(1, m + 1):
            pre = 0
            for j in range(1, n + 1):
                tmp = dp[j]
                dp[j] = max(dp[j - 1], dp[j], pre + (A[i - 1] == B[j - 1]))
                pre = tmp
        return dp[-1]
```

#### FASTEST
```
class Solution:
    def maxUncrossedLines(self, A, B) -> int:
        d = collections.defaultdict(list)
        for idx, val in enumerate(A):
            d[val].append(idx)
        dp = [0] * (len(A) + 1)
        for x in B:
            for j in reversed(d[x]):
                dp[j + 1] = max(dp[:j + 1]) + 1
        return max(dp)
```
