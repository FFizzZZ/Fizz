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
