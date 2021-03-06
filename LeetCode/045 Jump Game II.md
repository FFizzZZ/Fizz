```
class Solution:
    def jump(self, nums: List[int]) -> int:
        count = 0
        index = 0
        while index < len(nums) - 1:
            count += 1
            end = nums[index] + index
            if end >= len(nums) - 1: return count
            tmp = 0
            for i in range(index + 1, end + 1):
                if i + nums[i] > tmp:
                    tmp = i + nums[i]
                    index = i
        return count
```
## Leetcode
### 顺藤摸瓜
```
class Solution:
    def jump(self, nums: List[int]) -> int:
        index = end = count = 0
        for i in range(len(nums) - 1):
            if i + nums[i] > end:
                end = i + nums[i]
            if end >= len(nums) - 1:
                return count + 1
            if i == index:
                index = end
                count += 1
        return count
```

```
class Solution:
    def jump(self, nums: List[int]) -> int:
        end = reach = count = 0
        for idx, val in enumerate(nums):
            if idx + val > reach:
                reach = idx + val
            if idx == end:
                if end >= len(nums) - 1:
                    return count
                count += 1
                end = reach
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
