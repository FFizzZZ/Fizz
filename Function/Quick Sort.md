```
def quicksort(s):
    if len(s) <= 1: return s
    mid = s[len(s)//2]
    left, middle, right = [], [], []
    for i in s:
        if i < mid: left.append(i)
        elif i > mid: right.append(i)
        else: middle.append(i)
    return quicksort(left) + middle + quicksort(right)
```

#### In-Place
```
def partition(data, start, end):
    data[start], data[end] = data[end], data[start]
    small = start - 1
    for i in range(start, end):
        if data[i] < data[end]:
            small += 1
            if small != i:
                data[small], data[i] = data[i], data[small]
    small += 1
    data[end], data[small] = data[small], data[end]
    return small
        
def quicksort(data, start, end):
    if start == end:
        return
    idx = partition(data, start, end)
    if idx > start:
        quicksort(data, start, idx - 1)
    if idx < end:
        quicksort(data, idx + 1, end)
```

```
def quick_sort(nums, start, end):
    if start >= end:
        return
    val = nums[end]
    l, r = start, end
    while l < r:
        while l < r and nums[l] <= val:
            l += 1
        while l < r and nums[r] >= val:
            r -= 1
        if l < r:
            nums[l], nums[r] = nums[r], nums[l]
    nums[l], nums[end] = nums[end], nums[l]
    quick_sort(nums, start, l - 1)
    quick_sort(nums, l + 1, end)
```
