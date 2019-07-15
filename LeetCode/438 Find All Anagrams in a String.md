```
from collections import Counter
class Solution:
    def findAnagrams(self, s, p):
        res = []
        l = len(p)
        pCounter = Counter(p)
        sCounter = Counter(s[:l-1])
        for i in range(l-1,len(s)):
            sCounter[s[i]] += 1  
            if sCounter == pCounter:    
                res.append(i-l+1)  
            temp = s[i - l + 1]
            sCounter[temp] -= 1  
            if sCounter[temp] == 0:
                del sCounter[temp]
        return res
```
