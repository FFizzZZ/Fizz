## Leetcode
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
