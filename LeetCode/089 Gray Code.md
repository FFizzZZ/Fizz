```
class Solution:
    def grayCode(self, n):
        results = [0]
        for i in range(n):
            results += [x + 2 ** i for x in reversed(results)]
        return results
```

## Formula
```
class Solution:
    def grayCode(self, n):
        ans = []
        for i in range(1 << n):
            ans.append(i ^ i >> 1)
        return ans
```
