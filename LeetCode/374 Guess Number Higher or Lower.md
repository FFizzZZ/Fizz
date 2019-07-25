## Leetcode
```
class Solution(object):
    def guessNumber(self, n):
        low, high = 1, n
        while low <= high:
            mid = (low + high) // 2
            ans = guess(mid)
            if ans == 0:
                return mid
            elif ans < 0:
                high = mid - 1
            else:
                low = mid + 1
```
