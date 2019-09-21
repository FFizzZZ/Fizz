## Leetcode
#### Next Array
```
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        n = len(seats)
        left, right = [n] * n, [n] * n
        for i in range(n):
            if seats[i]:
                left[i] = 0
            elif i > 0:
                left[i] = left[i - 1] + 1
        for i in range(n - 1, -1, -1):
            if seats[i]:
                right[i] = 0
            elif i < n - 1:
                right[i] = right[i + 1] + 1
        return max(min(left[i], right[i]) for i, seat in enumerate(seats) if not seat)
```
#### Two Pointer
```
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        people = (i for i, seat in enumerate(seats) if seat)
        pre, future = None, next(people)
        ans = 0
        for i, seat in enumerate(seats):
            if seat:
                pre = i
            else:
                while future is not None and future < i:
                    future = next(people, None)
                left = i - pre if pre is not None else float('inf')
                right = future - i if future is not None else float('inf')
                ans = max(ans, min(left, right))
        return ans
```
#### Group by Zero
```
class Solution(object):
    def maxDistToClosest(self, seats):
        ans = 0
        for seat, group in itertools.groupby(seats):
            if not seat:
                L = len(list(group))
                ans = max(ans, (L + 1) // 2)
        return max(ans, seats.index(1), seats[::-1].index(1))
```

#### Intuitive
```
class Solution:
    def maxDistToClosest(self, seats):
        ans = 0
        pre = -1
        n = len(seats)
        for i in range(n):
            if seats[i]:
                ans = max(ans, i if pre == -1 else (i - pre) // 2)
                pre = i
        return max(ans, n - 1 - pre)
```
