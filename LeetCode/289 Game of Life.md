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
