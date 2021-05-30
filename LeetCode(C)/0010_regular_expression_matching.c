#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* recursion */
bool isMatch(char * s, char * p)
{
    int len_s = strlen(s);
    int len_p = strlen(p);
    bool ret;

    if (len_p == 0)
        return len_s == 0; 
    
    bool first = (len_s > 0) && (*p == *s || *p == '.');
    if (len_p > 1 && *(p + 1) == '*')
        ret = isMatch(s, p + 2) || (first && isMatch(s + 1, p));
    else
        ret = first && isMatch(s + 1, p + 1);

    return ret;
}

/* dynamic programming */
bool isMatch(char * s, char * p)
{
    int len_s = strlen(s);
    int len_p = strlen(p);
    bool dp[len_s + 1][len_p + 1];
    
    memset(dp, 0, sizeof(int) * (len_s + 1) * (len_p + 1));
    dp[len_s][len_p] = true;
    
    for (int i = len_s; i > -1; i--) {
        for (int j = len_p - 1; j > -1; j--) {
            int first = i < len_s && (p[j] == s[i] || p[j] == '.');
            if (j + 1 < len_p && p[j + 1] == '*')
                dp[i][j] = dp[i][j + 2] || (first && dp[i + 1][j]);
            else
                dp[i][j] = first && dp[i + 1][j + 1];
        }
    }

    return **dp;
}