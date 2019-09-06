## Leetcode
```
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        n = len(A)
        d = collections.defaultdict(list)
        for idx, val in enumerate(A):
            d[val].append(idx)
        dp = [[0] * n for _ in range(n)]
        for i in range(1, n - 1):
            for j in range(i + 1, n):
                val = 2 * A[i] - A[j]
                if val in d:
                    for k in d[val]:
                        if k < i:
                            dp[i][j] += dp[k][i] + 1
        ans = 0
        for row in dp:
            ans += sum(row)
        return ans
```
