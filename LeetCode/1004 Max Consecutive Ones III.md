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
