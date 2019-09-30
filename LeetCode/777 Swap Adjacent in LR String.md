## Leetcode
```
class Solution(object):
    def canTransform(self, start, end):
        if len(start) != len(end): return False
        A = [(a, idx) for idx, a in enumerate(start) if a in ["R", "L"]]
        B = [(b, idx) for idx, b in enumerate(end) if b in ["R", "L"]]
        if len(A) != len(B): return False
        for (a, i), (b, j) in zip(A, B):
            if a != b: return False
            if a == "L":
                if i < j: return False
            else:
                if i > j: return False
        return True
```
#### Faster
```
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        l, r, n = 0, 0, len(start)
        while l < n or r < n:
            while l < n and start[l] == "X":
                l += 1
            while r < n and end[r] == "X":
                r += 1
            if l == n or r == n:
                return l == r
            if start[l] != end[r]:
                return False
            elif start[l] == "L":
                if l < r: return False
            else:
                if l > r: return False
            l += 1; r += 1
        return l == r
```
