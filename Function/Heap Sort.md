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

## max_heapify 的非递归写法 
```
def maxheapify(A):
    length = len(A)
    if length <= 1: return A
    for i in range(length//2, -1, -1):
        index = i; val = A[i]; flag = 0
        while not flag and 2 * index + 1 < length:
            temp = 2 * index + 1
            if temp + 1 < length and A[temp+1] > A[temp]: 
                temp += 1
            if A[temp] <= val: 
                flag = 1
            else:
                A[index] = A[temp]
                index = temp
        A[index] = val
```
