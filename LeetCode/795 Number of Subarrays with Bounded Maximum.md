## Leetcode
```
class Solution:
    def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
        left = cnt = ans = 0
        for right, val in enumerate(A):
            if L <= val <= R:
                cnt = right - left + 1
                ans += cnt
            elif val < L:
                ans += cnt
            else:
                left = right + 1
                cnt = 0
        return ans
```
