```
def merge(left, right):
    ans = []
    l, r = 0, 0
    while l < len(left) and r < len(right):
        if left[l] < right[r]:
            ans.append(left[l])
            l += 1
        else:
            ans.append(right[r])
            r += 1
    ans.extend(left[l:])
    ans.extend(right[r:])
    return ans
def merge_sort(A):
    if len(A) <= 1: return A
    mid = len(A) // 2
    left = merge_sort(A[:mid])
    right = merge_sort(A[mid:])
    return merge(left, right)
```
