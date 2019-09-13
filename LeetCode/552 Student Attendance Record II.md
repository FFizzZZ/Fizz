## Leetcode
#### Dynamic Programming
https://leetcode.com/problems/student-attendance-record-ii/discuss/101643/Share-my-O(n)-C%2B%2B-DP-solution-with-thinking-process-and-explanation
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

#### FASTEST
https://leetcode.com/problems/student-attendance-record-ii/discuss/101633/Improving-the-runtime-from-O(n)-to-O(log-n)
```
import numpy as np
class Solution(object):
    def checkRecord(self, n):
        A = np.matrix([[0, 0, 1, 0, 0, 0],
                       [1, 0, 1, 0, 0, 0],
                       [0, 1, 1, 0, 0, 0],
                       [0, 0, 1, 0, 0, 1],
                       [0, 0, 1, 1, 0, 1],
                       [0, 0, 1, 0, 1, 1]])
        power = A
        mod = 10 ** 9 + 7
        while n:
            if n & 1:
                power = (power * A) % mod
            A = A ** 2 % mod
            n //= 2
        return power[5, 2]
```
