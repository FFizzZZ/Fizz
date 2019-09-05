## Leetcode

#### Brute Force
```
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        cnt = 0
        n = len(A)
        for start in range(n - 2):
            diff = A[start + 1] - A[start]
            for end in range(start + 2, n):
                if A[end] - A[end - 1] == diff:
                    cnt += 1
                else:
                    break
        return cnt
```

#### Dynamic Programming
```
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        n = len(A)
        pre = 0
        cnt = 0
        for i in range(2, n):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                pre += 1
                cnt += pre
            else:
                pre = 0
        return cnt
```

#### Formula
```
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        n = len(A)
        ans = 0
        cnt = 0
        for i in range(2, n):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                cnt += 1
            else:
                ans += (cnt + 1) * cnt // 2
                cnt = 0
        ans += (cnt + 1) * cnt // 2
        return ans
```
