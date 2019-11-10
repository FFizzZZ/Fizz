## Leetcode
## Recursion
```
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int[][] memo = new int[s1.length()][s2.length()];
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                memo[i][j] = -1;
            }
        }
        return dfs(s1, s2, s3, 0, 0, 0, memo);
    }
    
    public boolean dfs(String s1, String s2, String s3, int i, int j, int k, int[][] memo) {
        if (i == s1.length()) {
            return s2.substring(j).equals(s3.substring(k));
        }
        if (j == s2.length()) {
            return s1.substring(i).equals(s3.substring(k));
        }
        if (memo[i][j] >= 0) {
            return memo[i][j] == 1 ? true : false;
        }
        boolean ans = false;
        if (s3.charAt(k) == s1.charAt(i) && dfs(s1, s2, s3, i + 1, j, k + 1, memo) ||
            s3.charAt(k) == s2.charAt(j) && dfs(s1, s2, s3, i, j + 1, k + 1, memo)) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
}
```
