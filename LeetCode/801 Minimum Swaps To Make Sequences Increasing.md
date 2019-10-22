## Leetcode
#### Dynamic Programming
```
class Solution:
    def minSwap(self, A: List[int], B: List[int]) -> int:
        keep, swap = 0, 1
        for i in range(1, len(A)):
            k = s = float("inf")
            if A[i - 1] < A[i] and B[i - 1] < B[i]:
                k = keep
                if swap + 1 < s: s = swap + 1
            if A[i - 1] < B[i] and B[i - 1] < A[i]:
                if swap < k: k = swap
                if keep + 1 < s: s = keep + 1
            keep, swap = k, s
        return keep if keep < swap else swap
```

```
class Solution:
    def minSwap(self, A: List[int], B: List[int]) -> int:
        keep, swap = 0, 0
        a, b = -1, -1
        for i in range(len(A)):
            if a >= A[i] or b >= B[i]:
                swap, keep = keep + 1, swap
            elif a >= B[i] or b >= A[i]:
                swap += 1
            else:
                keep = min(swap, keep)
                swap = keep + 1
            a, b = A[i], B[i]
        return min(swap, keep)
```
