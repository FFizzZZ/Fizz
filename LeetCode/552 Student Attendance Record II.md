## Leetcode
```
class Solution(object):
    def checkRecord(self, n):
        if n == 1: return 3
        if n == 2: return 8
        m = 10 ** 9 + 7
        A, P, L = [0] * n, [0] * n, [0] * n
        P[0] = L[0] = A[0] = 1
        L[1] = 3
        A[1] = 2
        A[2] = 4
        for i in range(1, n):
            P[i] = (A[i - 1] + P[i - 1] + L[i - 1]) % m
            if i > 1:
                L[i] = (A[i - 1] + P[i - 1] + A[i - 2] + P[i - 2]) % m
            if i > 2:
                A[i] = (A[i - 1] + A[i - 2] + A[i - 3]) % m
        return (A[-1] + P[-1] + L[-1]) % m
```
