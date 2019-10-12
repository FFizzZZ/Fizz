```
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        dx = min(C, G) - max(A, E)
        dy = min(D, H) - max(B, F)
        overlap = dx * dy if dx > 0 and dy > 0 else 0
        total = (A - C) * (B - D) + (E - G) * (F - H)
        return total - overlap
```
