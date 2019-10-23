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
        
    
```
class Solution(object):
    def pushDominoes(self, dominoes):
        n = len(dominoes)
        force = [0] * n
        f = 0
        for i in range(n):
            if dominoes[i] == "R": f = n
            elif dominoes[i] == "L": f = 0
            else: f = f - 1 if f > 0 else 0
            force[i] += f
        for i in range(n - 1, -1, -1):
            if dominoes[i] == "L": f = n
            elif dominoes[i] == "R": f = 0
            else: f = f - 1 if f > 0 else 0
            force[i] -= f
        return "".join("." if f == 0 else "R" if f > 0 else "L" for f in force)
```
        
        
        
        
