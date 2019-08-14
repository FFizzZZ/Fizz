## Leetcode
```
class Solution:
    def kthSmallestPrimeFraction(self, A: List[int], K: int) -> List[int]:
        l, r = 1 / A[-1], 1
        n = len(A)
        while l < r:
            mid = (l + r) / 2
            p, q, cnt = 0, 0, 0
            maxvalue = -1
            i = 0
            for j in range(n - 1):
                while i < n and A[j] / A[i] > mid:
                    i += 1
                if i == n:
                    break
                cnt += n - i
                
                if A[j] / A[i] > maxvalue:
                    p = A[j]
                    q = A[i]
                    maxvalue = p / q
            if cnt == K:
                return [p, q]
            elif cnt > K:
                r = mid
            else:
                l = mid
```
