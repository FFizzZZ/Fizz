```
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        d = [(1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)]
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                tmp = self.count(i, j, board, m, n, d)
                if board[i][j] == 1:
                    if tmp < 2 or tmp > 3:
                        board[i][j] = 2
                elif board[i][j] == 0:
                    if tmp == 3:
                        board[i][j] = 3
        for i in range(m):
            for j in range(n):
                if board[i][j] == 2:
                    board[i][j] = 0
                elif board[i][j] == 3:
                    board[i][j] = 1
        
    def count(self, i, j, board, m, n, d):
        count = 0
        for dx, dy in d:
            x = i + dx
            y = j + dy
            if 0 <= x < m and 0 <= y < n:
                if board[x][y] in [1, 2]:
                    count += 1
        return count
```
