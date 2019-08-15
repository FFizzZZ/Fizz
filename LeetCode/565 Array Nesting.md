## Leetcode
```
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        visited = [0] * len(nums)
        ans = 0
        for x in nums:
            cnt = 0
            while not visited[x]:
                visited[x] = 1
                cnt += 1
                x = nums[x]
            ans = max(cnt, ans)
        return ans
```

#### Without Extra Space
```
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            cnt = 0
            tmp = i
            while nums[tmp] != -1:
                nums[tmp], tmp = -1, nums[tmp]
                cnt += 1
            if cnt > ans:
                ans = cnt
        return ans
```
