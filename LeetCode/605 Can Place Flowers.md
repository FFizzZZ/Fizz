```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        ans = 0
        num = 0
        flowerbed = [0] + flowerbed + [0, 1]
        for x in flowerbed:
            if x == 0:
                num += 1
            else:
                if num > 0:
                    ans += (num - 1) // 2
                num = 0
        return ans >= n
```
