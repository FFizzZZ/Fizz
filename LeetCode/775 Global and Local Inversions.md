## Leetcode

```
class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        cur = 0
        for i in range(len(A) - 2):
            cur = max(cur, A[i])
            if cur > A[i + 2]:
                return False
        return True
```

```
class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        return all(abs(idx - val) <= 1 for idx, val in enumerate(A))
```
