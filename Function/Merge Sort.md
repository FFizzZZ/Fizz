## Recursive Version
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

## Iterative Version
```
def mergesort(nums):
    n = len(nums)
    l = 1
    while l < n:
        for i in range(0, n - l, 2 * l):
            nums1, nums2 = nums[i:i + l], nums[i + l:i + 2 * l]
            tmp = f(nums1, nums2)
            nums[i:i+len(tmp)] = tmp
        l *= 2
    return nums
def f(a, b):
    ans = []
    while a and b:
        val1, val2 = a[0], b[0]
        if val1 < val2:
            ans.append(a.pop(0))
        else:
            ans.append(b.pop(0))
    ans.extend(a or b)
    return ans
```
