## Leetcode
```
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        N = len(grid)
        memo = dict()
        def dp(r1, c1, r2):
            if (r1, c1, r2) in memo: return memo[r1, c1, r2]
            c2 = r1 + c1 - r2
            if N in [r1, c1, r2, c2] or grid[r1][c1] == -1 or grid[r2][c2] == -1:
                return -1
            if r1 == c1 == N - 1:
                return grid[-1][-1]
            a = dp(r1 + 1, c1, r2 + 1)
            b = dp(r1 + 1, c1, r2)
            c = dp(r1, c1 + 1, r2 + 1)
            d = dp(r1, c1 + 1, r2)
            ans = max(a, b, c, d)
            if ans != -1:
                if r1 == r2 and c1 == c2:
                    ans += grid[r1][c1]
                else:
                    ans += grid[r1][c1] + grid[r2][c2]
            memo[r1, c1, r2] = memo[r2, c2, r1] = ans
            return ans
        return max(0, dp(0, 0, 0))
```
        

            
 
