## Leetcode
```
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        dp = {float("-inf"): 0}
        arr2.sort()
        for x in arr1:
            new_dp = collections.defaultdict(lambda: float('inf'))
            for key in dp:
                if x > key:
                    new_dp[x] = min(new_dp[x], dp[key])
                idx = bisect.bisect_right(arr2, key)
                if idx < len(arr2):
                    new_dp[arr2[idx]] = min(new_dp[arr2[idx]], dp[key] + 1)
            dp = new_dp
        return min(dp.values()) if dp else -1
```
#### FASTER
```
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2.sort()
        dp = {0: float("-inf")}
        for x in arr1:
            new_dp = dict()
            for key in dp:
                if dp[key] < x and (key not in new_dp or new_dp[key] > x):
                    new_dp[key] = x
                idx = bisect.bisect_right(arr2, dp[key])
                if idx < len(arr2) and (key + 1 not in new_dp or new_dp[key + 1] > arr2[idx]):
                    new_dp[key + 1] = arr2[idx]
            dp = new_dp
        return min(dp.keys()) if dp else -1
```
