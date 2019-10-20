## Leetcode
```
class Solution:
    def shoppingOffers(self, price, special, needs):
            n = len(needs)
            def dfs(cur, idx):
                ans = sum(cur[i] * price[i] for i in range(n))
                for i in range(idx, len(special)):
                    s = special[i]
                    new = cur[:]
                    flag = 0
                    for j in range(n):
                        tmp = new[j] - s[j]
                        if tmp < 0:
                            flag = 1
                            break
                        new[j] = tmp
                    if flag == 0:
                        val = dfs(new, i) + s[-1]
                        if val < ans: 
                            ans = val
                return ans
            return dfs(needs, 0)
```
            
```
class Solution:
    def shoppingOffers(self, price, special, needs):
        return self.dfs(price, special, needs, 0)
    
    def dfs(self, price, special, needs, idx):
        ans = sum(needs[i] * price[i] for i in range(len(needs)))
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
        return ans
```


