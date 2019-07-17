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
        
```
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        if not tasks: return 0
        task_counts = list(collections.Counter(tasks).values())
        M = max(task_counts)
        Mct = task_counts.count(M)
        val = (M - 1) * (n + 1) + Mct
        l = len(tasks)
        return val if val > l else l
```
        
        
        
        
        
        
        
        
 
 
