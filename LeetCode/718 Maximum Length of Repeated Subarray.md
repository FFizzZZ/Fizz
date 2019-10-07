## Leetcode
#### Dynamic Programming
##### Let dp[i][j] be the longest length of common suffix
```
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        m, n = len(A), len(B)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if A[i - 1] == B[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
        return max(max(row) for row in dp)
```

###### Optimized Version
```
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        m, n = len(A), len(B)
        dp = [0] * (n + 1)
        ans = 0
        for i in range(1, m + 1):
            pre = 0
            for j in range(1, n + 1):
                tmp = dp[j]
                if A[i - 1] == B[j - 1]:
                    dp[j] = pre + 1
                else:
                    dp[j] = 0      # Pay Attention Here!
                pre = tmp
            ans = max(ans, max(dp))
        return ans
```
