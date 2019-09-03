## Leetcode

#### Greedy
```
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        digits = []
        A = list(map(int, str(N)))
        for i in range(len(A)):
            for d in range(1, 10):
                if digits + [d] * (len(A) - i) > A:
                    digits.append(d - 1)
                    break
            else: digits.append(9)
        return int(''.join(map(str, digits)))
```

#### Truncate After Cliff
```
class Solution(object):
    def monotoneIncreasingDigits(self, N):
        S = list(str(N))
        i = 1
        while i < len(S) and S[i-1] <= S[i]:
            i += 1
        while 0 < i < len(S) and S[i-1] > S[i]:
            S[i-1] = str(int(S[i-1]) - 1)
            i -= 1
        S[i+1:] = '9' * (len(S) - i-1)
        return int("".join(S))
```

```
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        index = 0
        num = list(str(N))
        n = len(num)
        
        while index < n - 1 and num[index] <= num[index + 1]:
            index += 1
        if index == n - 1: return N
        
        while index > 0 and num[index] == num[index - 1]:
            index -= 1
        
        num[index] = str(int(num[index]) - 1)
        num[index + 1:] = '9' * (n - index - 1)
        return int(''.join(num))
```
