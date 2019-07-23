```
class Solution(object):
    def isHappy(self, n):
        d = set()
        while 1:
            if n in d: return False
            d.add(n)
            val = 0
            while n:
                n, tmp = divmod(n, 10)
                val += tmp ** 2
            if val == 1: return True
            n = val
```

## Leetcode
#### Floyd Cycle Detection
```
class Solution(object):
    def isHappy(self, n):
        slow = self.f(n)
        fast = self.f(self.f(n))
        while slow != fast:
            slow = self.f(slow)
            fast = self.f(self.f(fast))
        if slow == 1:
            return True
        else:
            return False      
    def f(self, n):
        ans = 0
        while n:
            n, val = divmod(n, 10)
            ans += val ** 2
        return ans
```
