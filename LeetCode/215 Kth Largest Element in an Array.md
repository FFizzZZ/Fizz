```
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)
        l, r = 0, n - 1
        while l <= r:
            index = self.partition(l, r, nums)
            if index == n - k:
                return nums[index]
            elif index < n - k:
                l = index + 1
            else:
                r = index - 1       
    def partition(self, l, r, nums):
        mid = (l + r) // 2
        val = nums[mid]
        nums[mid], nums[r] = nums[r], nums[mid]
        index = l - 1
        for i in range(l, r):
            if nums[i] < val:
                index += 1
                if index != i:
                    nums[index], nums[i] = nums[i], nums[index]
        index += 1
        nums[r], nums[index] = nums[index], nums[r]
        return index
```
