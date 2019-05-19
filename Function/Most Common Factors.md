```
def f(m, n):
    while n:
        r = m % n
        m = n
        n = r
    return m
```

## 多个数的最大公约数
```
def k(nums):
    if len(nums) == 1:
        return nums[0]
    m = min([x for x in nums if x != 0])
    return k([x % m for x in nums if x != m and x != 0] + [m])
```

最小公倍数 = 两数乘积 ➗ 最大公约数
