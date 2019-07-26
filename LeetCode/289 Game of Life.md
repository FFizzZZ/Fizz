```
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        neighbors = [(1,0), (1,-1), (0,-1), (-1,-1), (-1,0), (-1,1), (0,1), (1,1)]
        rows, cols = len(board), len(board[0])
        for row in range(rows):
            for col in range(cols):
                count = 0
                for dx, dy in neighbors:
                    r, c = row + dx, col + dy
                    if (r < rows and r >= 0) and (c < cols and c >= 0) and abs(board[r][c]) == 1:
                        count += 1
                if board[row][col] == 1 and (count < 2 or count > 3):
                    board[row][col] = -1
                if board[row][col] == 0 and count == 3:
                    board[row][col] = 2
        for row in range(rows):
            for col in range(cols):
                if board[row][col] > 0:
                    board[row][col] = 1
                else:
                    board[row][col] = 0
```

## Leetcode
```
class Solution:
    def gameOfLife(self, board):
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                count = 0
                for I in range(max(0, i - 1), min(i + 2, m)):
                    for J in range(max(0, j - 1), min(j + 2, n)):
                        count += board[I][J] & 1
                if count == 3 or count == 4 and board[i][j] == 1:
                    board[i][j] |= 2
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1
```

```
class Solution:
    def gameOfLifeInfinite(self, live):
        ctr = collections.Counter((I, J) for i, j in live for I in range(i-1, i+2)
                                  for J in range(j-1, j+2) if I != i or J != j)
        return {ij for ij in ctr if ctr[ij] == 3 or ctr[ij] == 2 and ij in live}

    def gameOfLife(self, board):
        live = {(i, j) for i, row in enumerate(board) for j, live in enumerate(row) if live}
        live = self.gameOfLifeInfinite(live)
        for i, row in enumerate(board):
            for j in range(len(row)):
                row[j] = int((i, j) in live)
```
