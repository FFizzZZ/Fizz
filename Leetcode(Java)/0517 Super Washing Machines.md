## Leetcode
```
class Solution {
    public int findMinMoves(int[] machines) {
        int total = 0;
        for (int i: machines) total += i;
        if (total % machines.length != 0) return -1;
        int avg = total / machines.length, count = 0, max = 0;
        for (int load: machines) {
            count += load - avg;
            max = Math.max(Math.max(max, Math.abs(count)), load - avg);
        }
        return max;
    }
}
```
