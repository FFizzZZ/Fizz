```
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        count = [0] * 121
        for age in ages:
            count[age] += 1
        ans = 0
        for a, cnt_a in enumerate(count):
            for b, cnt_b in enumerate(count):
                if a * 0.5 + 7 >= b: continue
                if a < b: continue
                if a < 100 < b: continue
                ans += cnt_a * cnt_b
                if a == b: ans -= cnt_a
        return ans
```

## Leetcode

#### ageA < ageB <= 0.5*ageA+7, 0.5ageA < 7, ageA < 14
```
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        cnt = [0] * 121
        for age in ages:
            cnt[age] += 1
        prefix = [0] * 121
        for i in range(1, 121):
            prefix[i] = cnt[i] + prefix[i - 1]
        ans = 0
        for i in range(15, 121):
            if cnt[i] == 0: continue
            count = prefix[i] - prefix[int(0.5 * i + 7)]
            ans += count * cnt[i] - cnt[i]
        return ans
  ```
