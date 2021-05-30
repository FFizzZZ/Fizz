#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10000

char get_pair(char c)
{
    switch (c) {
        case ')':
            return '(';
        case ']':
            return '[';
        case '}':
            return '{';
    }

    return 0;
}

bool isValid(char * s)
{
    char stack[SIZE];
    int top = -1;

    for (char c = *s; c != 0; s++, c = *s) {
        char pair = get_pair(c);
        if (pair != 0) {
            if (top < 0 || stack[top--] != pair)
                return false;
        } else
            stack[++top] = c;
    }
    
    return top == -1;
}