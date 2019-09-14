```
class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        n = len(A)
        for i in range(n - 2, -1, -1):
            if A[i] > A[i + 1]:
                index = None
                val = -1
                for j in range(i, n):
                    if A[j] < A[i]:
                        if A[j] > val:
                            val = A[j]
                            index = j
                if index:
                    A[i], A[index] = A[index], A[i]
                    return A
        return A
```
## Leetcode
```
class Solution:
    def prevPermOpt1(self, A):
        n = len(A)
        for left in range(n - 2, -1, -1):
            if A[left] > A[left + 1]:
                break
        else:
            return A
        right = A.index(max(a for a in A[left + 1:] if a < A[left]), left)
        A[left], A[right] = A[right], A[left]
        return A
```
