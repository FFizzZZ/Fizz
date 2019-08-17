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

```
class Solution:
    def combine(self, n, k):
        ans = collections.deque([[i] for i in range(k, n + 1)])
        for i in range(1, k):
            for _ in range(len(ans)):
                tmp = ans.popleft()
                for j in range(k - i, tmp[0]):
                    ans.append([j] + tmp)
        return ans
```

```
class Solution:
    def combine(self, n, k):
        ans = []
        self.f(1, n, k, [], ans)
        return ans
    def f(self, start, n, k, path, ans):
        if len(path) == k:
            ans.append(path[:])      ## pay attention to [:] here !!!
            return
        else:
            for i in range(start, n - k + len(path) + 2):
                path.append(i)
                self.f(i + 1, n, k, path, ans)
                path.pop()           ## save memory usage 
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

## interesting
```
class Solution:
    def combine(self, n, k):
        result = []
        i = 0
        p = [0] * k
        while i >= 0:
            p[i] += 1
            if p[i] > n:
                i -= 1
            elif i == k - 1:
                result.append(p[:])
            else:
                i += 1
                p[i] = p[i - 1]
        return result
```
