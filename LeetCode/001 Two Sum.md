```
class Solution:
    def twoSum(self, nums: 'List[int]', target: 'int') -> 'List[int]':
        dict = {}
        for index, num in enumerate(nums):
            if num in dict:
                return dict[num], index
            dict[target - num] = index
```
