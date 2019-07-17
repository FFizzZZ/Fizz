## Leetcode
```
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        l = len(tasks)
        d = list(collections.Counter(tasks).values())
        m = max(d)
        count = d.count(m)
        
        parts = m - 1
        partlength = n - (count - 1)
        empty = parts * partlength
        available = l - m * count
        idles = empty - available
        if idles < 0:
            idles = 0
        return l + idles
```
        
       

        
        
        
        
        
        
        
        
 
 
