```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        ans = 0
        n = len(grid)
        for i in range(n):
            for j in range(n):
                tmp = grid[i][j]
                if tmp:
                    ans += 2 + 4 * tmp
        for i in range(n):
            row = grid[i]
            for j in range(1, n):
                ans -= 2 * min(row[j], row[j - 1]) 
        for j in range(n):
            for i in range(1, n):
                ans -= 2 * min(grid[i][j], grid[i - 1][j])   
        return ans
```

## Leetcode
```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        ans = 0
        n = len(grid)
        for i in range(n):
            for j in range(n):
                tmp = grid[i][j]
                if tmp:
                    ans += 2 + 4 * tmp
        for row in grid:
            ans -= self.f(row)
        for col in zip(*grid):
            ans -= self.f(col)
        return ans
    def f(self, nums):
        cnt = 0
        for i in range(1, len(nums)):
            cnt += 2 * min(nums[i - 1], nums[i])
        return cnt
```
