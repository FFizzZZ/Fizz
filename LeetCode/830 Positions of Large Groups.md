## Leetcode

```
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        ans = []
        l = 0
        for r, char in enumerate(S):
            if r == len(S) - 1 or S[r] != S[r + 1]:
                if r - l + 1 >= 3:
                    ans.append([l, r])
                l = r + 1
        return ans
```
