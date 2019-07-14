## Leetcode
##### One important speedup is that we can ensure all the 0 values of each group occur at the end of the array groups, by enforcing if (groups[i] == 0) break;. This greatly reduces repeated work - for example, in the first run of search, we will make only 1 recursive call, instead of k. Actually, we could do better by skipping any repeated values of groups[i], but it isn't necessary.
##### Another speedup is we could sort the array nums, so that we try to place the largest elements first. When the answer is true and involves subsets with a low size, this method of placing elements will consider these lower size subsets sooner. We can also handle elements nums[i] >= target appropriately. These tricks are not necessary to solve the problem, but they are presented in the solutions below.
```
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        target, rem = divmod(sum(nums), k)
        if rem: return False
        def search(groups):
            if not nums: return True
            v = nums.pop()
            for i, group in enumerate(groups):
                if group + v <= target:
                    groups[i] += v
                    if search(groups): return True
                    groups[i] -= v
                if not group: break
            nums.append(v)
            return False
        
        nums.sort()
        if nums[-1] > target: return False
        while nums and nums[-1] == target:
            nums.pop()
            k -= 1
        return search([0] * k)
```
