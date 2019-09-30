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
