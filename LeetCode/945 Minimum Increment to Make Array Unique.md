## Leetcode
```
class Solution:
    def minIncrementForUnique(self, A):
        if not A: return 0
        ans = 0
        A.sort()
        pre = A[0]
        for i in range(1, len(A)):
            if A[i] <= pre:
                ans += pre - A[i] + 1
                pre += 1
            else:
                pre = A[i]
        return ans
```

```
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        count = collections.Counter(A)
        taken = []
        ans = 0
        for x in range(100000):
            if count[x] >= 2:
                taken.extend([x] * (count[x] - 1))
            elif taken and count[x] == 0:
                ans += x - taken.pop()
        return ans
```

```
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        A.append(100000)
        ans = taken = 0
        for i in range(1, len(A)):
            if A[i - 1] == A[i]:
                taken += 1
                ans -= A[i]
            else:
                give = min(taken, A[i] - A[i - 1] - 1)
                ans += give * (give + 1) // 2 + give * A[i - 1]
                taken -= give
        return ans
```

```
class Solution:
    def minIncrementForUnique(self, A):
        res = need = 0
        for i in sorted(A):
            res += max(need - i, 0)
            need = max(need + 1, i + 1)
        return res
```
