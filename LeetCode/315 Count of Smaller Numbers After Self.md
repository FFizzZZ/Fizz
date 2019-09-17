```
class Solution:
    def countSmaller(self, nums):
        if not nums: return []
        ans = [0]
        num = [nums[-1]]
        for i in range(len(nums) - 2, -1, -1):
            index = self.find(num, nums[i])
            ans.append(index)
            num.insert(index, nums[i])
        return ans[::-1]
    def find(self, num, target):
        l, r = 0, len(num) - 1
        if target < num[0]: return 0
        if target > num[-1]: return r + 1
        while l < r:
            mid = (l + r) // 2
            val = num[mid]
            if val < target:
                l = mid + 1
            else:
                r = mid
        return l
```

## Leetcode
```
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums: return []
        sortednums = [nums[-1]]
        ans = [0]
        for i in range(len(nums) - 2, -1, -1):
            val = nums[i]
            idx = bisect.bisect_left(sortednums, val)
            ans.append(idx)
            sortednums[idx:idx] = [val]
        return ans[::-1]
```
