## Leetcode

```
class Solution(object):
    def sortedSquares(self, A):
        return sorted(x*x for x in A)
```

```
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        n = len(A)
        j = bisect.bisect_left(A, 0)
        i = j - 1
        ans = []
        while i >=0 and j < n:
            if A[i] ** 2 < A[j] ** 2:
                ans.append(A[i] ** 2)
                i -= 1
            else:
                ans.append(A[j] ** 2)
                j += 1
        while i >= 0:
            ans.append(A[i] ** 2)
            i -= 1
        while j < n:
            ans.append(A[j] ** 2)
            j += 1
        return ans
```
