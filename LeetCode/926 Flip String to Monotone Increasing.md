## Prefix Sum
```
class Solution:
    def minFlipsMonoIncr(self, S: str) -> int:
        n = len(S)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + int(S[i])
        ans = n
        for i in range(n + 1):
            tmp = prefix[i] + n - i - (prefix[n] - prefix[i])
            if tmp < ans: ans = tmp
        return ans
```


## One Pass
```
class Solution:
    def minFlipsMonoIncr(self, S: str) -> int:
        flip = one = 0
        for char in S:
            if char == '0':
                if one == 0:
                    continue
                else:
                    flip += 1
            else:
                one += 1
            if flip > one:
                flip = one
        return flip
```
