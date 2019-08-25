```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = sum(nums[:3])
        diff = abs(ans - target)
        n = len(nums)
        for i in range(n - 2):
            if i > 0 and nums[i - 1] == nums[i]: continue
            val = nums[i]
            l, r = i + 1, n - 1
            Min = val + nums[l] + nums[l + 1]
            Max = val + nums[r - 1] + nums[r]
            if Max <= target:
                if Max == target:
                    return target
                elif target - Max < diff:
                    ans = Max
                    diff = target - Max
                continue
            elif Min >= target:
                if Min == target:
                    return target
                elif Min - target < diff:
                    diff = Min - target
                    ans = Min
                continue
            else:
                while l < r:
                    tmp = val + nums[l] + nums[r]
                    if tmp == target:
                        return target
                    if abs(tmp - target) < diff:
                        ans = tmp
                        diff = abs(tmp - target)
                    if tmp < target:
                        while l < r and nums[l] == nums[l + 1]:
                            l += 1
                        l += 1
                    else:
                        while l < r and nums[r] == nums[r - 1]:
                            r -= 1
                        r -= 1
        return ans
```


                    
