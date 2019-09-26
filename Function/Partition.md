```
def partition(s, start, end):
    mid = (start + end) // 2
    s[end], s[mid] = s[mid], s[end]
    small = start - 1
    for i in range(start, end):
        if s[i] < s[end]:
                small += 1
                if i != small:
                    s[small], s[i] = s[i], s[small]
    small += 1
    s[small], s[end] = s[end], s[small]
    return small
```

```
def partition(nums, start, end):
    l, r = start, end
    pivot = nums[end]
    while l < r:
        while l < r and nums[l] <= pivot:
            l += 1
        while l < r and nums[r] >= pivot:
            r -= 1
        if l < r:
            nums[l], nums[r] = nums[r], nums[l]
    nums[end], nums[l] = nums[l], nums[end]
    return l
```
