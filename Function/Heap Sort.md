```
def max_heapify(A, heap_size, i):
    left = 2 * i + 1
    right = 2 * i + 2
    largest = i
    if left < heap_size and A[left] > A[largest]:
        largest = left
    if right < heap_size and A[right] > A[largest]:
        largest = right
    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        max_heapify(A, heap_size, largest)

def build_heap(A):
    heap_size = len(A)
    for i in range ((heap_size//2),-1,-1):
        max_heapify(A,heap_size, i)

def heapsort(A):
    heap_size = len(A)
    build_heap(A)
    print(A) #uncomment this print to see the heap it builds
    for i in range(heap_size-1,0,-1):
        A[0], A[i] = A[i], A[0]
        heap_size -= 1
        max_heapify(A, heap_size, 0)
```

## heapify 的非递归写法 
```
def heapify(nums):
    n = len(nums)
    for i in range(n // 2, -1, -1):
        index = i
        val = nums[i]
        while 2 * index + 1 < n:
            tmp = 2 * index + 1
            if tmp + 1 < n and nums[tmp] > nums[tmp + 1]:
                tmp += 1
            if val < nums[tmp]:
                break
            nums[index] = nums[tmp]
            index = tmp
        nums[index] = val
```

#### Build_heap O(n)
https://www.jianshu.com/p/7cf64b02c0a4

