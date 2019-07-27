## Leetcode
```
class Solution:
    def topKFrequent(self, nums, k):
        count = collections.Counter(nums)   
        return heapq.nlargest(k, count.keys(), key=count.get) 
        # or
        return sorted(count.keys(), key = count.get, reverse = True)[:k]

```
#### Bucket Sort
```
class Solution:
    def topKFrequent(self, nums, k):
        bucket = [[] for _ in range(len(nums))]
        count = collections.Counter(nums)
        
        for key in count:
            frequency = count.get(key)
            bucket[frequency - 1].append(key)
        
        ans = []
        for index in range(len(bucket) - 1, -1, -1):
            ans.extend(bucket[index])
            if len(ans) == k: return ans
```
```
class Solution:
    def topKFrequent(self, nums, k):
        bucket = [[] for _ in nums]
        for num, freq in collections.Counter(nums).items():
            bucket[-freq].append(num)
        return list(itertools.chain(*bucket))[:k]
```
