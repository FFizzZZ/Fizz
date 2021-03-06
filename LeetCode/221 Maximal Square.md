## Leetcode
#### Dynamic Programming
```
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        n = len(matrix)
        r, c = len(matrix), len(matrix[0])
        dp = [[0] * (c + 1) for _ in range(r + 1)]
        ans = 0
        for i in range(1, r + 1):
            for j in range(1, c + 1):
                if matrix[i - 1][j - 1] == '1':
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                    if dp[i][j] > ans:
                        ans = dp[i][j]
        return ans ** 2
```
##### Optimized Version
```
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        n = len(matrix)
        r, c = len(matrix), len(matrix[0])
        dp = [0] * (c + 1)
        ans = 0
        pre = 0
        for i in range(1, r + 1):
            for j in range(1, c + 1):
                temp = dp[j]
                if matrix[i - 1][j - 1] == '1':
                    dp[j] = min(dp[j], dp[j - 1], pre) + 1
                    if dp[j] > ans:
                        ans = dp[j]
                else:
                    dp[j] = 0
                pre = temp
        return ans ** 2
```
