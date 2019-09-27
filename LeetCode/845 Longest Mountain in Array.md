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
                    
```
class Solution:
    def longestMountain(self, A):
        ans = up = down = 0
        for i in range(1, len(A)):
            if down and A[i] > A[i - 1] or A[i] == A[i - 1]:
                up = down = 0
            up += A[i] > A[i - 1]
            down += A[i] < A[i - 1]
            if up and down:
                ans = max(ans, up + down + 1)
        return ans
```
#### FASTEST
```
class Solution:
    def longestMountain(self, A: List[int]) -> int:
        n = len(A)
        if n < 3: return 0
        up = None
        ans = 0     
        for i in range(1, n):
            if up == None:
                if A[i] > A[i-1]:
                    start = i - 1
                    up = True
            elif up == True:
                if A[i] < A[i-1]:
                    up = False
                elif A[i] == A[i-1]:
                    up = None
            elif up == False:
                tmp = i - start
                if tmp > ans: ans = tmp
                if A[i] > A[i-1]:
                    start = i - 1
                    up = True
                elif A[i] == A[i-1]:
                    up = None
        if up == False:
            tmp = i + 1 - start
            if tmp > ans: ans = tmp
        return ans
```
        
        
