```
class Solution:
    def maxPoints(self, points):
        l = len(points)
        if l <= 2: return l
        ans = 0
        d = collections.defaultdict(int)
        for i in range(l - 1):
            d.clear()
            overlap, Max = 0, 0
            for j in range(i + 1, l):
                x = points[i][0] - points[j][0]
                y = points[i][1] - points[j][1]
                if x == 0 and y == 0:
                    overlap += 1
                    continue
                gcd = self.gcd(x, y)
                x /= gcd
                y /= gcd
                d[(x, y)] += 1
                count = d[(x, y)]
                if count > Max: Max = count
            tmp = Max + overlap + 1
            if tmp > ans: ans = tmp
        return ans
                
    def gcd(self, x, y):
        if y == 0: return x
        return self.gcd(y, x % y)
```
