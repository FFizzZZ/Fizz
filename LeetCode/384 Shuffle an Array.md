## Leetcode
#### Brute Force
```
class Solution:
    def __init__(self, nums):
        self.array = nums
        self.original = list(nums)

    def reset(self):
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        aux = list(self.array)
        for idx in range(len(self.array)):
            remove_idx = random.randrange(len(aux))
            self.array[idx] = aux.pop(remove_idx)
        return self.array
```

#### Fisher-Yates Algorithm
```
class Solution:
    def __init__(self, nums):
        self.original = nums

    def reset(self):
        return self.original

    def shuffle(self):
        array = self.original[:]
        for i in range(len(array)):
            swap_idx = random.randrange(i, len(array))
            array[i], array[swap_idx] = array[swap_idx], array[i]
        return array
```

#### FASTEST
```
class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums
    def reset(self) -> List[int]:
        return self.nums
    def shuffle(self) -> List[int]:
        return sorted(self.nums, key = lambda x: random.random())
```

```
class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums
    def reset(self) -> List[int]:
        return self.nums
    def shuffle(self) -> List[int]:
        array = self.nums[:]
        random.shuffle(array)
        return array
```
