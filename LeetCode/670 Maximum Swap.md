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
