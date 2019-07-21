## Leetcode
####
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
        while y != 0:
            x, y = y, x % y
        return x
```

#### 
```
class Solution:
    def maxPoints(self, points):
        if len(points) == 0:
            return 0
        line_table = collections.defaultdict(int)
        for x, y in points:
            line_table[(x, y)] += 1
        keys = list(line_table.keys())
        N = len(keys)
        if N == 1:
            return line_table[keys[0]]
        result = 0
        for i in range(N-1):
            slopes = collections.defaultdict(int)
            for j in range(i + 1, N):
                dx, dy = keys[i][0] - keys[j][0], keys[i][1] - keys[j][1]
                if dy == 0:
                    slope = 0
                else:
                    slope = dx/dy
                slopes[slope] += line_table[keys[j]]
            tmp = line_table[keys[i]] + max(slopes.values())
            if tmp > result: result = tmp
        return result    
```
