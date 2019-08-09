## Leetcode
```
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        AB = collections.Counter(a+b for a in A for b in B)
        return sum(AB[-c-d] for c in C for d in D)
```

```
from collections import defaultdict
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        n = len(A)
        if n == 0: return 0
        dictA, dictB = defaultdict(int), defaultdict(int)
        dictC, dictD = defaultdict(int), defaultdict(int)
        dictAB = defaultdict(int)
        count = 0
        for i in range(n):
            dictA[A[i]] += 1
            dictB[B[i]] += 1
            dictC[C[i]] += 1
            dictD[D[i]] += 1
        for itemA in dictA:
            for itemB in dictB:
                anb = itemA + itemB
                dictAB[anb] += dictA[itemA]*dictB[itemB]

        for itemC in dictC:
            for itemD in dictD:
                anb = -itemC - itemD
                count += dictAB[anb] * dictC[itemC] * dictD[itemD]
        return count
```

#### FASTEST!!
```
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        nn = len(A)
        if 0 == nn:
            return 0
        dictA = {}
        dictB = {}
        dictC = {}
        dictD = {}
        dictAB = {}
        count = 0
        for i in range(nn):
            if A[i] in dictA:
                dictA[A[i]] += 1
            else:
                dictA[A[i]] = 1
            if B[i] in dictB:
                dictB[B[i]] += 1
            else:
                dictB[B[i]] = 1
            if C[i] in dictC:
                dictC[C[i]] += 1
            else:
                dictC[C[i]] = 1
            if D[i] in dictD:
                dictD[D[i]] += 1
            else:
                dictD[D[i]] = 1
        for itemA in dictA:
            for itemB in dictB:
                anb = itemA + itemB
                if anb in dictAB:
                    dictAB[anb] += dictA[itemA]*dictB[itemB]
                else:
                    dictAB[anb] = dictA[itemA]*dictB[itemB]

        for itemC in dictC:
            for itemD in dictD:
                anb = -itemC-itemD
                if anb in dictAB:
                    count += dictAB[anb]*dictC[itemC]*dictD[itemD]
        return count
```
