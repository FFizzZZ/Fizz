```
class Solution:
    def combine(self, n, k):
        ans = [[x] for x in range(1, n + 1)]
        for x in range(k-1):
            for i in range(len(ans)):
                temp = ans.pop(0)
                for j in range(temp[-1] + 1, n - k + x + 3):
                    ans.append(temp + [j])
        return ans
```

## bulit-in
```
from itertools import combinations
class Solution:
    def combine(self, n, k):
        return list(combinations(range(1, n + 1), k))
```

## recurse
```
class Solution:
    def combine(self, n, k):
        if k == 0:
            return [[]]
        return [pre + [i] for i in range(k, n + 1) for pre in self.combine(i - 1, k - 1)]
```
