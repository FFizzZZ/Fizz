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
#### DFS with memorization
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
#### Dynamic Version (but much slower) 
```
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        counts = collections.defaultdict(int)
        for string in strs:
            ones = string.count("1")
            counts[ones, len(string) - ones] += 1
        nums = list(counts.keys())
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for ones, zeros in nums:
            for i in range(m, -1, -1):
                for j in range(n, -1, -1):
                    times = counts[ones, zeros]
                    if ones > 0: times = min(times, j // ones)
                    if zeros > 0: times = min(times, i // zeros)
                    ans = 0
                    for k in range(times + 1):
                        tmp = k + dp[i - k * zeros][j - k * ones]
                        ans = max(tmp, ans)
                    dp[i][j] = ans
        return dp[-1][-1]
```
