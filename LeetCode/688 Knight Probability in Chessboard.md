```
class Solution:
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        direction = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
        memo = dict()
        return self.dfs(r, c, N, K, direction, memo)
    def dfs(self, x, y, N, K, direction, memo):
        if K == 0:
            return 1 if 0 <= x < N and 0 <= y < N else 0
        if (x, y, K) in memo: return memo[x, y, K]
        ans = 0
        for dx, dy in direction:
            x_new = x + dx; y_new = y + dy
            if 0 <= x_new < N and 0 <= y_new < N:
                ans += self.dfs(x_new, y_new, N, K - 1, direction, memo)
        ans /= 8
        memo[x, y, K] = ans
        return ans
```

## Leetcode
```
class Solution(object):
    def knightProbability(self, N, K, r, c):
        dp = [[0] * N for _ in range(N)]
        dp[r][c] = 1
        directions = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
        for _ in range(K):
            cur = [[0] * N for _ in range(N)]
            for x, row in enumerate(dp):
                for y, val in enumerate(row):
                    for dx, dy in directions:
                        x_new = x + dx; y_new = y + dy;
                        if 0 <= x_new < N and 0 <= y_new < N:
                            cur[x_new][y_new] += val / 8
            dp = cur
        return sum(map(sum, dp))
```

#### FASTEST
```
class Solution:
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        if K == 0: return 1
        def helper(x, y):
            if not 0 <= x < N or not 0 <= y < N:
                return 0
            if 2 * x > N - 1:
                x = N - 1 - x
            if 2 * y > N - 1:
                y = N - 1 - y
            if x > y:
                x, y = y, x
            return pre[x][y]
        directions = [(1, 2), (1, -2), (-1, 2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)]
        half = (N + 1) // 2
        pre = [[1] * half for _ in range(half)]
        cur = [[0] * half for _ in range(half)]
        for _ in range(K - 1):
            for x in range(half):
                for y in range(x, half):
                    cur[x][y] = sum(helper(x + dx, y + dy) for dx, dy in directions) / 8
            pre, cur = cur, pre
        return sum(helper(r + dx, c + dy) for dx, dy in directions) / 8
```
