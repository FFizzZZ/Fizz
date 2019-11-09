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
