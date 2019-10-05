```
class Solution:
    def longestOnes(self, A, K):
        num = 0
        idx = 0
        ans = 0
        for i, val in enumerate(A):
            if val == 0:
                num += 1
                if num > K:
                    while A[idx] != 0:
                        idx += 1
                    idx += 1
                    num -= 1
            tmp = i - idx + 1
            if tmp > ans:
                ans = tmp
        return ans
```

## Leetcode
#### Amazing Algorithm!
```
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        i = 0
        for j in range(len(A)):
            if not A[j]:
                K -= 1
            if K < 0:
                if not A[i]:
                    K += 1
                i += 1
        return j - i + 1
```
