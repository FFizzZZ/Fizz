## Leetcode
#### Recurse
```
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        if not board: return 
        row, col = len(board), len(board[0])
        if row <= 1 or col <= 1: return
        for i in range(row):
            self.check(board, i, 0, row, col)
            self.check(board, i, col - 1, row, col)
        for j in range(1, col - 1):
            self.check(board, 0, j, row, col)
            self.check(board, row - 1, j, row, col)
        for i in range(row):
            for j in range(col):
                if board[i][j] == '1':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
    def check(self, board, i, j, row, col):
        if board[i][j] == 'O':
            board[i][j] = '1'
            if i > 1: self.check(board, i - 1, j, row, col)
            if j > 1: self.check(board, i, j - 1, row, col)
            if i + 1 < row: self.check(board, i + 1, j, row, col)
            if j + 1 < col: self.check(board, i, j + 1, row, col)
```

#### Iterative
```
class Solution:
    def solve(self, board):
        if not board: return
        queue = []
        m, n = len(board), len(board[0])
        for r in range(m):
            for c in range(n):
                if (r in [0, m - 1] or c in [0, n - 1]) and board[r][c] == "O":
                    queue.append((r, c))
        while queue:
            r, c = queue.pop()
            if 0 <= r < m and 0 <= c < n and board[r][c] == "O":
                board[r][c] = "D"
                queue.extend([(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)])
        for r in range(m):
            for c in range(n):
                if board[r][c] == "O":
                    board[r][c] = "X"
                elif board[r][c] == "D":
                    board[r][c] = "O"
```
