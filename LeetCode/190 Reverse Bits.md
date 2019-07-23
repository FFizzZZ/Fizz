## Leetcode
```
class Solution:
    def reverseBits(self, n):
        res = 0
        for _ in xrange(32):
            res = (res<<1) + (n&1)
            n>>=1
        return res
```

```
class Solution:
    def reverseBits(self, n):
        oribin='{0:032b}'.format(n)
        reversebin=oribin[::-1]
        return int(reversebin,2)
```
