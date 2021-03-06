```
class Solution:
    def findDuplicate(self, nums):
        for v in nums:
            v = abs(v)
            if nums[v] < 0:
                return v
            else:
                nums[v] *= -1
```

## Leetcode
##### The idea is almost the same as finding the entrance to the cycle in a linked list.
```
class Solution:
    def findDuplicate(self, nums):
        # Find the intersection point of the two runners.
        tortoise = nums[0]
        hare = nums[0]
        while True:
            tortoise = nums[tortoise]
            hare = nums[nums[hare]]
            if tortoise == hare:
                break       
        # Find the "entrance" to the cycle.
        ptr1 = nums[0]
        ptr2 = tortoise
        while ptr1 != ptr2:
            ptr1 = nums[ptr1]
            ptr2 = nums[ptr2]       
        return ptr1
```
#### Binary Search
```
class Solution(object):
    def findDuplicate(self, nums):
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            count = 0
            for i in nums:
                if i <= mid:
                    count += 1
            if count <= mid:
                l = mid + 1
            else:
                r = mid
        return r
```
