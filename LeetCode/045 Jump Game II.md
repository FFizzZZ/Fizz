```
class Solution:
    def jump(self, nums: List[int]) -> int:
        count = 0
        index = 0
        while index < len(nums) - 1:
            count += 1
            end = index + nums[index]
            if end >= len(nums) - 1: return count
            temp = 0
            for i in range(index + 1, end + 1):
                if i + nums[i] > temp:
                    temp = i + nums[i]
                    index = i
        return count
```
## Leetcode
### 顺藤摸瓜
```
class Solution:
    def jump(self, nums: List[int]) -> int:
        count = 0
        index = 0
        temp = 0
        for i in range(len(nums) - 1):
            if i + nums[i] > temp:
                temp = i + nums[i]
            if temp >= len(nums) - 1:
                return count + 1
            if i == index:
                count += 1
                index = temp
        return count
```

### 顺挂摸藤，必须排掉较差的情况，否则超过时间限制
```
class Solution:
    def jump(self, nums: List[int]) -> int:
        if all([x == 1 for x in nums]): return len(nums) - 1
        index = len(nums) - 1
        count = 0
        while index:
            for i in range(index):
                if i + nums[i] >= index:
                    index = i
                    count += 1
                    break
        return count                                  
```
