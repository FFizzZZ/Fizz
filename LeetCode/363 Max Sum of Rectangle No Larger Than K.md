## Leetcode
```
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        if not matrix: return 0
        ans = float("-inf")
        m, n = len(matrix), len(matrix[0])
        for i in range(n):
            sums = [0] * m
            for j in range(i, n):
                for row in range(m):
                    sums[row] += matrix[row][j]
                cur = 0
                res = float("-inf")
                for x in sums:
                    if cur < 0:
                        cur = x
                    else:
                        cur += x
                    if cur > res: res = cur
                if res <= k:
                    ans = max(ans, res)
                    continue
                cur = 0
                array = [0]
                res = float("-inf")
                for x in sums:
                    cur += x
                    idx = bisect.bisect_left(array, cur - k)
                    if idx < len(array):
                        res = max(res, cur - array[idx])
                    bisect.insort(array, cur)
                ans = max(ans, res)
        return ans
```
