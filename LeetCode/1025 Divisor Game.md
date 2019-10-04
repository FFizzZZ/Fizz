## Leetcode
```
class Solution:
    def divisorGame(self, N: int) -> bool:
        return N % 2 == 0
```
* If N is even.
We can choose x = 1.
The opponent will get N - 1, which is a odd.
Reduce to the case odd and he will lose.

* If N is odd,
We have to choose an odd x.
The opponent will get N - x, which is a even.
Reduce to the case even and he will win.

So the N will change odd and even alternatively until N = 1.
