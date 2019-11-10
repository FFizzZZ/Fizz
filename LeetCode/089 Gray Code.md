## Leetcode
```
class Solution:
    def grayCode(self, n):
        ans = [0]
        for i in range(n):
            ans += [x + (1 << i) for x in reversed(ans)]
        return ans
```

## Formula
```
class Solution:
    def grayCode(self, n):
        ans = []
        for i in range(1 << n):
            ans.append(i ^ i >> 1)
        return ans
```

How to prove?  
(1) we can prove that all generated numbers are unique.  
Say x = i ^ i >> 1, y = j ^ j >> 1. If x = y, then we have x ^ y = 0, so (i ^ j) ^ ( i >>1 ^ j >>1) = 0.  
Suppose i ^ j = a_1a_2...a_n, then i >> 1 ^ j >> 1 = 0a_1a_2...a_n-1.  
From (i ^ j) ^ ( i >>1 ^ j >>1) = 0, we know  
a_1 ^ 0 = 0 --> a_1 = 0  
a_1 ^ a_2 = 0 --> a_2= 0  
....  
so i ^ j = 0 ---> i = j.  
As a result, we know that x = y <=> i = j.  
(2) we can prove that successive numbers have exact one bit that is different.  
Find the rightmost 0 in the sequence and compare i ^ i >> 1 and (i + 1) ^ (i + 1) >> 1, we can prove it.  
