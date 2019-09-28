```
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for s in strs:
            ones = s.count('1')
            zeros = len(s) - ones
            for i in range(m, zeros - 1, -1):
                for j in range(n, ones - 1, -1):
                        dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1)
        return dp[-1][-1]
```

## Leetcode
```
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        counts = collections.defaultdict(int)
        for s in strs:
            zeros = s.count('0')
            counts[(zeros, len(s) - zeros)] += 1
        nums = list(counts.keys())
        def dfs(idx, m, n, d):
            if idx == len(nums): return 0
            if (idx, m, n) in d: return d[idx, m, n]
            zeros, ones = nums[idx]
            ans = 0
            q = counts[zeros, ones]
            if zeros > 0:
                q = min(q, m // zeros)
            if ones > 0:
                q = min(q, n // ones)
            for i in range(q + 1):
                tmp = i + dfs(idx + 1, m - i * zeros, n - i * ones, d)
                ans = max(ans, tmp)
            d[idx, m, n] = ans
            return ans
        return dfs(0, m, n, dict())
```
