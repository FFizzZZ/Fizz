```
class Solution(object):
    def hammingWeight(self, n):
        ans = 0
        while n:
            ans += n & 1
            n >>= 1
        return ans
```

## Leetcode

```
class Solution(object):
    def hammingWeight(self, n):
        ans = 0
        while n:
            ans += 1
            n &= (n - 1)
        return ans
```

```
class Solution(object):
    def hammingWeight(self, n):
        return bin(n).count('1')
```
