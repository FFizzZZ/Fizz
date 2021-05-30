#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    char *map[128] = {0};
    int ans = 0;
    char *l = s;

    while (*s != 0) {
        if (map[*s] > 0) 
            l = map[*s] + 1 > l ? map[*s] + 1 : l;
        ans = s - l + 1 > ans ? s - l + 1 : ans;
        map[*s] = s;
        s++;
    }

    return ans;
}