#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char c)
{
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

char * reverseVowels(char * s){
    int l = 0;
    int r = strlen(s) - 1;

    while (l < r) {
        while (l < r && !isVowel(s[l]))
            l++;
        
        while (l < r && !isVowel(s[r]))
            r--;

        if (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }

    return s;
}