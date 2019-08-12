## Leetcode
#### Permutations TLE
```
class Solution(object):
    def reorderedPowerOf2(self, N):
        return any(cand[0] != '0' and bin(int("".join(cand))).count('1') == 1
                   for cand in itertools.permutations(str(N)))
```

#### Counting
```
class Solution(object):
    def reorderedPowerOf2(self, N):
        count = collections.Counter(str(N))
        return any(count == collections.Counter(str(1 << b)) for b in range(31))
```

#### FASTEST
if N has k digits, then its rearrangements are between 10^(k-1) and 10^k

so the powers of 2 it could be have powers between (k-1)log_2(10) and klog_2(10)
```
from collections import Counter
class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        k = int(math.log10(N))
        tmp = int(math.log(10, 2))
        
        d = Counter(str(N))
        for x in range(k * tmp, (k + 1) * (tmp + 1)):
            if d == Counter(str(2 ** x)):
                return True
        return False
```
