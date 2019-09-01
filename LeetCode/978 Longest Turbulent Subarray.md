## Leetcode
```
class Solution(object):
    def maxTurbulenceSize(self, A):
        N = len(A)
        ans = 1
        anchor = 0

        for i in range(1, N):
            c = A[i-1] - A[i]
            if c == 0:
                anchor = i
            elif i == N-1 or c * (A[i] - A[i+1]) >= 0:
                ans = max(ans, i - anchor + 1)
                anchor = i
        return ans
```
