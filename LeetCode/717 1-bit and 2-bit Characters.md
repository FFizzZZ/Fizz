```
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        idx = 0
        while idx < len(bits):
            if bits[idx] == 0:
                idx += 1
                flag = 1
            else:
                idx += 2
                flag = 0
            if idx == len(bits):
                return True if flag else False
```

## Leetcode
```
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        idx = 0
        while idx < len(bits) - 1:
            idx += bits[idx] + 1
        return idx == len(bits) - 1
```

#### Best
```
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        ones = 0
        for i in range(len(bits) - 2, -1, -1):
            if bits[i] == 0: break
            ones += 1
        return False if ones % 2 == 1 else True
```
