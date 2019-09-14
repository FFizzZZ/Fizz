## Leetcode
#### Using Two Arrays
```
class Solution:
    def candy(self, ratings: List[int]) -> int:
        cnt = 0
        n = len(ratings)
        left = [1] * n
        right = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                left[i] = left[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right[i] = right[i + 1] + 1
        for i in range(n):
            cnt += max(left[i], right[i])
        return cnt
```

#### One Arrays
```
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        candies = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
        cnt = candies[n - 1]
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)
            cnt += candies[i]
        return cnt
```

#### Single Pass Approach with Constant Space
```
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n == 0: return 0
        cnt = 1
        up = down = peak = 0
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                up += 1
                down = 0
                peak = up
                cnt += 1 + up
            elif ratings[i] < ratings[i - 1]:
                up = 0
                down += 1
                cnt += 1 + down - (peak >= down)
            else:
                peak = down = up = 0
                cnt += 1
        return cnt
```

```
class Solution:
    def candy(self, ratings: List[int]) -> int:
        peak = pre = float('inf')
        down = 0
        up = 1
        cnt = 0
        for n in ratings:
            if n < pre:
                down += 1
                if down == peak:
                    down += 1
                up = 1
                cnt += down
            elif n > pre:
                down = 0
                up += 1
                peak = up
                cnt += peak
            else:
                down = 0
                up = peak = 1
                cnt += 1
            pre = n
        return cnt
```
