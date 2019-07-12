## Leetcode
```
class Solution:
    def countBits(self, num: int) -> List[int]:
        ans = [0] * (num + 1)
        for i in range(1, num + 1):
            ans[i] = ans[i >> 1] + (i & 1)    # Pay attention to () here!
        return ans
```

```
class Solution:
    def countBits(self, num: int) -> List[int]:
        ans = [0] * (num + 1)
        for i in range(1, num + 1):
            ans[i] = ans[i & (i - 1)] + 1
        return ans
```
