#include <stdio.h>
#include <string.h>

#define SIZE (2 * 1000 + 1)

void str2array(char *c, char *string, int *len)
{
    int i = 0;

    while (*c != 0) {
        string[2 * i] = '#';
        string[2 * i + 1] = *c;
        c++;
        i++;
    }
    string[2 * i] = '#';

    *len = i;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

char * longestPalindrome(char * s)
{
    char string[SIZE];
    int dp[SIZE];
    int c = 0;
    int r = 0;
    int center = 0;
    int radius = 0;
    int len = 0;

    str2array(s, string, &len);

    for (int i = 0; i < 2 * len + 1; i++) {
        if (center + radius > i)
            dp[i] = min(center + radius - i, dp[center * 2 - i]);
        else
            dp[i] = 1;

        while (i + dp[i] < len && i - dp[i] >= 0 && 
        string[i + dp[i]] == string[i - dp[i]]) {
            dp[i]++;
        }

        if (center + radius < i + dp[i]) {
            center = i;
            radius = dp[i];
        }

        if (r < dp[i]) {
            c = i;
            r = dp[i];
        }
    }

    return (c - r + 1) / 2, (c + r - 1) / 2;
}


// int max(int x, int y)
// {
//     return x > y ? x : y;
// }

// int expand(int l, int r, char *s, int len)
// {
//     for (; l > -1 && r < len; l--, r++) {
//         if (s[l] != s[r])
//             break;
//     }

//     return r - l - 1;
// }


// char * longestPalindrome(char * s){
//     int len = strlen(s);
//     int ans = 0;
//     int idx = 0;

//     for (int i = 0; i < len; i++) {
//         int len1 = expand(i, i, s, len);
//         int len2 = expand(i, i + 1, s, len);
//         int m = max(len1, len2);

//         if (m > ans) {
//             ans = m;
//             idx = len1 > len2 ? (i - m / 2) : (i - m / 2 + 1);
//         }
//     }

//     char *ret = (char *)malloc(ans + 1);
//     strncpy(ret, s + idx, ans);
//     s[ans] = 0;

//     return ret;
// }