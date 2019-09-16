```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for row in board:
            d = collections.Counter(row)
            for key, val in d.items():
                if val > 1 and key != '.':
                    return False
        for col in zip(*board):
            d = collections.Counter(col)
            for key, val in d.items():
                if val > 1 and key != '.':
                    return False
        for i in range(3):
            row = board[3*i:3*(i+1)]
            for j in range(3):
                temp = [x[3*j:3*(j+1)] for x in row]
                square = temp[0] + temp[1] + temp[2]
                counts = [square.count(x) for x in square if x != '.']
                if sum(counts) != len(counts):
                    return False
        return True
```

## Leetcode
```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        visited = set()
        for i in range(9):
            for j in range(9):
                val = board[i][j]
                if val == '.':
                    continue
                if (i, val) in visited or (val, j) in visited or (i // 3, j // 3, val) in visited:
                    return False
                else:
                    visited.add((i, val))
                    visited.add((val, j))
                    visited.add((i // 3, j // 3, val))
        return True
```
```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:       
        for row in board:
            d = set()
            for num in row:
                if num == '.': continue
                if num in d: 
                    return False
                d.add(num)
        for col in zip(*board):
            d = set()
            for num in col:
                if num == '.': continue
                if num in d:
                    return False
                d.add(num)
        for row in range(3):
            for col in range(3):
                x, y = 3 * row, 3 * col
                d = set()
                for i in range(x, x + 3):
                    for j in range(y, y + 3):
                        val = board[i][j]
                        if val == '.': continue
                        if val in d:
                            return False
                        d.add(val)
        return True
```

------------------------------------------------------------
                    
```                
class Solution:
    def isValidSudoku(self, board):
        return 1 == max(list(collections.Counter(
            x
            for i, row in enumerate(board)
            for j, c in enumerate(row)
            if c != '.'
            for x in ((c, i), (j, c), (i//3, j//3, c))
        ).values()) + [1])
```      
        
* Solution 1

Using Counter. One logical line, seven physical lines.
```
def isValidSudoku(self, board):
    return 1 == max(collections.Counter(
        x
        for i, row in enumerate(board)
        for j, c in enumerate(row)
        if c != '.'
        for x in ((c, i), (j, c), (i/3, j/3, c))
    ).values() + [1])
```
The + [1] is only for the empty board, where max would get an empty list and complain. It's not necessary to get it accepted here, as the empty board isn't among the test cases, but it's good to have.

* Solution 2

Using len(set).
```
def isValidSudoku(self, board):
    seen = sum(([(c, i), (j, c), (i/3, j/3, c)]
                for i, row in enumerate(board)
                for j, c in enumerate(row)
                if c != '.'), [])
    return len(seen) == len(set(seen))
```
Solution 3

Using any.
```
def isValidSudoku(self, board):
    seen = set()
    return not any(x in seen or seen.add(x)
                   for i, row in enumerate(board)
                   for j, c in enumerate(row)
                   if c != '.'
                   for x in ((c, i), (j, c), (i/3, j/3, c)))
```
* Solution 4

Iterating a different way.
```
def isValidSudoku(self, board):
    seen = sum(([(c, i), (j, c), (i/3, j/3, c)]
                for i in range(9) for j in range(9)
                for c in [board[i][j]] if c != '.'), [])
    return len(seen) == len(set(seen))
```
