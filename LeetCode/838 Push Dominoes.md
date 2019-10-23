## Leetcode
```
class Solution(object):
    def pushDominoes(self, dominoes):
        direction = [(-1, "L")] + [(i, c) for i, c in enumerate(dominoes) if c != "."] + [(len(dominoes), "R")]
        ans = list(dominoes)
        for (i, x), (j, y) in zip(direction, direction[1:]):
            if x == y:
                for mid in range(i + 1, j):
                    ans[mid] = x
            elif x > y:
                for mid in range(i + 1, j):
                    if mid - i == j - mid: ans[mid] = "."
                    elif mid - i < j - mid: ans[mid] = "R"
                    else: ans[mid] = "L"
        return "".join(ans)
```
        
        
        
        
        
        
