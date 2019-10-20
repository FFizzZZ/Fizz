## Leetcode
```
class Solution:
    def shoppingOffers(self, price, special, needs):
            d = dict()
            n = len(needs)
            def dfs(cur):
                val = sum(cur[i] * price[i] for i in range(n))
                for s in special:
                    tmp = [cur[j] - s[j] for j in range(n)]
                    if min(tmp) >= 0:
                        val = min(val, d.get(tuple(tmp), dfs(tmp)) + s[-1])
                d[tuple(cur)] = val
                return val
            return dfs(needs)
```
            
```
class Solution:
    def shoppingOffers(self, price, special, needs):
        return self.dfs(price, special, needs, 0)
    
    def dfs(self, price, special, needs, idx):
        ans = float("inf")
        for i in range(idx, len(special)):
            s = special[i]
            new = needs[:]
            flag = 0
            for j in range(len(needs)):
                remain = needs[j] - s[j]
                if remain < 0:
                    flag = 1
                    break
                new[j] = remain
            if flag == 1: continue
            val = s[-1] + self.dfs(price, special, new, i)
            if val < ans: ans = val
        cur = 0
        for i in range(len(needs)):
            cur += needs[i] * price[i]
        return min(cur, ans)
```
