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
