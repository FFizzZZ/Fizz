## Leetcode
```
class Solution:
    def lastRemaining(self, n: int) -> int:
        left = True
        cnt = n
        step = 1
        head = 1
        while cnt > 1:
            if left or cnt % 2:
                head += step
            step *= 2
            cnt //= 2
            left = not left
        return head
```
