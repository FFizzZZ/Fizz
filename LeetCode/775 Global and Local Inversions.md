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
