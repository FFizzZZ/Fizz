## Leetcode
```
class Solution:
    def countTriplets(self, A: List[int]) -> int:
        counts = collections.defaultdict(int)
        for x in A:
            for y in A:
                counts[x & y] += 1
        ans = 0
        for x in A:
            for key in counts.keys():
                if x & key == 0:
                    ans += counts[key]
        return ans
```

#### Venn Diagram
```
class Solution:
    def countTriplets(self, A: 'List[int]') -> 'int':
        nums = []
        for x in A:
            nums.append(bin(x)[2:])
        maxlen = max(len(row) for row in nums)
        for idx, val in enumerate(nums):
            extra = maxlen - len(val)
            nums[idx] = "0" * extra + val
        row, col = len(nums), len(nums[0])
        ones = collections.defaultdict(set)
        for j in range(col):
            for i in range(row):
                if nums[i][j] == "1":
                    ones[j].add(i)        
        Venn = collections.defaultdict(list)
        cnt = 0
        for j in range(col):
            if len(ones[j]) != 0:
                cnt += len(ones[j]) ** 3
                for i in range(j, 0, -1):
                    for pre in Venn[i]:
                        intersection = pre & ones[j]
                        if len(intersection) != 0:
                            cnt += (-1) ** i * len(intersection) ** 3
                            Venn[i + 1].append(intersection)
                Venn[1].append(ones[j])
        return row ** 3 - cnt
````

```
from math import ceil, log2
class Solution:
    def countTriplets(self, A: 'List[int]') -> 'int':
        n, d = len(A), ceil(log2(max(A) + 1))
        aux = {j: {i for i, a in enumerate(A) if a & (1<<j)} for j in range(d)}

        Venn, cnt = collections.defaultdict(list), 0
        for j, one in aux.items():
            if len(one) == 0: continue
            cnt+= len(one)**3
            for i in range(j, 0, -1):
                overlap = [prv & one for prv in Venn[i]]
                cnt += (-1)**i * sum(len(x)**3 for x in overlap if x)
                Venn[i + 1] += [x for x in overlap if x]
            Venn[1].append(one)
        
        return n**3 - cnt
```
