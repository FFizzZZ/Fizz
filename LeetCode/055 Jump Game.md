```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        temp = 0
        l = len(nums)
        for i in range(l-1):
            if temp >= i:
                if temp < nums[i] + i:
                    temp = nums[i] + i
            else:
                return False
        return True if temp >= len(nums) - 1 else False
```

## 只有一个点的最大跳跃距离nums[i] == 0且我们不能跳得比这个点更远的时候，我们才无法到达最后
```
class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """ 
        if not nums or len(nums) <= 1: return True
        for i in range(len(nums)-2, -1, -1):
            if nums[i] == 0:
                flag = False
                for j in range(i):
                    if j + nums[j] > i:
                        flag = True
                        break
                if not flag:
                    return False
        return True
```
