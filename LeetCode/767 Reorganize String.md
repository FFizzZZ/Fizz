## Leetcode
#### Sort by Count
```
class Solution(object):
    def reorganizeString(self, S):
        n = len(S)
        ans = []
        d = collections.Counter(S)
        for char, cnt in sorted(d.items(), key = lambda x: x[1]):
            if cnt > (n + 1) // 2:
                return ""
            ans.extend(char * cnt)
        ans[::2], ans[1::2] = ans[n // 2:], ans[:n // 2]
        return "".join(ans)
```

#### Greedy with Heap
```
class Solution(object):
    def reorganizeString(self, S):
        n = len(S)
        d = collections.Counter(S)
        if any(x > (n + 1) // 2 for x in d.values()):
            return ""
        pq = [(-cnt, char) for char, cnt in d.items()]
        heapq.heapify(pq)
        ans = []
        while len(pq) >= 2:
            cnt1, char1 = heapq.heappop(pq)
            cnt2, char2 = heapq.heappop(pq)
            ans.extend([char1, char2])
            if cnt1 + 1: heapq.heappush(pq, (cnt1 + 1, char1))
            if cnt2 + 1: heapq.heappush(pq, (cnt2 + 1, char2))
        return "".join(ans) + (pq[0][1] if pq else "")
```
