## Leetcode
```
class LargerNumKey(str):
    def __lt__(x, y):
        return x+y > y+x
        
class Solution:
    def largestNumber(self, nums):
        largest_num = ''.join(sorted(map(str, nums), key=LargerNumKey))
        return '0' if largest_num[0] == '0' else largest_num
```

```
from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums):
        num = sorted(map(str, nums), key = cmp_to_key(lambda x, y: -1 if x + y > y + x else 1))
        return ''.join(num) if num[0] != '0' else '0'
```
