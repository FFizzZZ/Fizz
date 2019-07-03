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
    
-----------------------------------------------------
# 顺藤摸瓜
class Solution:
    def jump(self, nums: List[int]) -> int:
        step = 0
        temp = 0
        end = 0
        for i in range(len(nums)-1):
            temp = max(temp, nums[i] + i)
            if i == end:
                end = temp
                step += 1
        return step

# 顺挂摸藤，必须排掉较差的情况，否则超过时间限制
class Solution:
    def jump(self, nums: List[int]) -> int:
        if all([x == 1 for x in nums]): return len(nums) - 1
        p = len(nums) - 1
        leftmost = len(nums) - 1
        steps = 0
        while p > 0:
            for i in range(len(nums)):
                if i + nums[i] >= p:
                    p = i
                    steps += 1
                    break
        return steps
