##### My thoughy: "0" group in the middle will offer (N - 1) // 2 while on the two side will offer N // 2
```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        ans = 0
        num = 1
        for x in flowerbed:
            if x == 0:
                num += 1
            else:
                if num > 0:
                    ans += (num - 1) // 2
                num = 0
        if num != 0: ans += num // 2
        return ans >= n
```

## Leetcode
```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        cnt = 1
        for f in flowerbed:
            if f == 0:
                cnt += 1
            else:
                cnt = 0
            if cnt == 3:
                n -= 1
                cnt = 1
            if n == 0: return True
        if cnt == 2: n -= 1
        return n == 0
```
