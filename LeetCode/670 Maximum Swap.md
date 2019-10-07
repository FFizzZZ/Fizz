```
class Solution:
    def maximumSwap(self, num: int) -> int:
        string = list(str(num))
        for i in range(len(string) - 1):
            max_num = string[i]
            idx = None
            for j in range(len(string) - 1, i, -1):
                if string[j] > max_num:
                    max_num = string[j]
                    idx = j
            if idx:
                string[i], string[idx] = string[idx], string[i]
                return int("".join(string))
        return num
```

## Leetcode
#### Use HashMap to record index
```
class Solution:
    def maximumSwap(self, num: int) -> int:
        A = list(map(int, str(num)))
        last = {val: idx for idx, val in enumerate(A)}
        for idx, val in enumerate(A):
            for digit in range(9, val, -1):
                if last.get(digit, -1) > idx:
                    A[idx], A[last[digit]] = A[last[digit]], A[idx]
                    return int("".join(map(str, A)))
        return num
```
