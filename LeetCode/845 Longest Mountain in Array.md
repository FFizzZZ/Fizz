## Leetcode
#### Two Pointers
```
class Solution:
    def longestMountain(self, A: List[int]) -> int:
        ans = idx = 0
        n = len(A)
        while idx < n:
            i = idx
            if i + 1 < n and A[i + 1] > A[i]:
                while i + 1 < n and A[i + 1] > A[i]:
                    i += 1
                if i + 1 < n and A[i + 1] < A[i]:
                    while i + 1 < n and A[i + 1] < A[i]:
                        i += 1
                    ans = max(i - idx + 1, ans)
            idx = max(idx + 1, i)
        return ans
```
                    
                
        
        
