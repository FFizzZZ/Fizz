## Recursion
```
class Solution {
    public boolean isMatch(String s, String pattern) {
        if (pattern.isEmpty()) return s.isEmpty();
        boolean first_match = !s.isEmpty() && (pattern.charAt(0) == '.' || pattern.charAt(0) == s.charAt(0));
        if (pattern.length() >= 2 && pattern.charAt(1) == '*') {
            return (isMatch(s, pattern.substring(2)) ||
                   (first_match && isMatch(s.substring(1), pattern)));
        }
        else {
            return first_match && isMatch(s.substring(1), pattern.substring(1));
        }
    }
}
```

## Dynamic Programming
```
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        dp[s.length()][p.length()] = true;
        for (int i = s.length(); i > -1; i--) {
            for (int j = p.length() - 1; j > -1; j--) {
                boolean first_match = (i < s.length() && (p.charAt(j) == s.charAt(i) ||
                                      p.charAt(j) == '.'));
                if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                    dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
                }
                else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
}
```
