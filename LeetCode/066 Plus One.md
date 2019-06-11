```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        flag = 1
        l = len(digits)
        index = l - 1
        while flag:
            if digits[index] == 9:
                digits[index] = 0
                index -= 1
            else:
                if index >= 0:
                    digits[index] += 1
                else:
                    digits = [1] + digits
                flag = 0
        return digits
```

```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits)-1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                break
            else:
                digits[i] = 0
        if digits[0] == 0: digits = [1] + digits
        return digits
```
