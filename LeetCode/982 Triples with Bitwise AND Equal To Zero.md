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

#### Venn Graph
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
