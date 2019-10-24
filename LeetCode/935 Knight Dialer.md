## Leetcode

#### Dynamic Programming
```
class Solution:
    def knightDialer(self, N: int) -> int:
        M = 10 ** 9 + 7
        moves = [[4, 6], [6, 8], [7, 9], [4, 8], [3, 9, 0], [], [1, 7, 0], [2, 6], [1, 3], [2, 4]]
        dp = [1] * 10
        for _ in range(N - 1):
            new = [0] * 10
            for node, count in enumerate(dp):
                for nxt in moves[node]:
                    new[nxt] = (new[nxt] + count) % M
            dp = new
        return sum(dp) % M
```
##### Trick
```
dp = [[1] * 10]
M = 10 ** 9 + 7
moves = [[4, 6], [6, 8], [7, 9], [4, 8], [3, 9, 0], [], [1, 7, 0], [2, 6], [1, 3], [2, 4]]
class Solution: 
    def knightDialer(self, N: int) -> int:
        while len(dp) < N:
            new = [0] * 10
            for node, count in enumerate(dp[-1]):
                for nxt in moves[node]:
                    new[nxt] = (new[nxt] + count) % M
            dp.append(new)
        return sum(dp[-1]) % M
```




