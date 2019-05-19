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
