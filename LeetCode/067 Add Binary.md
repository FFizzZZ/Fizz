```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        temp = 0
        ans = ''
        i, j = len(a) - 1, len(b) - 1
        while i >=0 or j >= 0:
            x = int(a[i]) if i >= 0 else 0
            y = int(b[j]) if j >= 0 else 0
            i -= 1
            j -= 1
            s = x + y + temp
            temp = 0
            if s <= 1:
                ans = str(s) + ans
            else:
                temp = 1
                ans = str(s % 2) + ans
        return '1' + ans if temp else ans
```

```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2)+int(b, 2))[2:]
```
