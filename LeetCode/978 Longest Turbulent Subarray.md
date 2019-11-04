## Leetcode
```
class Solution(object):
    def maxTurbulenceSize(self, A):
        n = len(A)
        start = 0
        ans = 1
        for i in range(1, n):
            diff = A[i] - A[i - 1]
            if diff == 0:
                start = i
            elif i == n - 1 or diff * (A[i + 1] - A[i]) >= 0:
                ans = max(ans, i - start + 1)
                start = i
        return ans
```


```
class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
        if len(A) < 2: return len(A)
        ans = cur = 1
        up = A[0] < A[1]
        if A[0] != A[1]:
            ans += 1
            cur += 1
        for i in range(1, len(A) - 1):
            if (up and A[i] > A[i + 1]) or (not up and A[i] < A[i + 1]):
                cur += 1
                up = not up
            else:
                ans = max(ans, cur)
                cur = 2 - (A[i] == A[i + 1])
        return max(ans, cur)
```
