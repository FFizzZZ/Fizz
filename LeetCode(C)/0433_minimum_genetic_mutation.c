#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BANK_LEN 10
#define LEN 8

bool isInList(char *s, char **list, int size)
{
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i], s) == 0)
            return true;
    }

    return false;
}


int minMutation(char * start, char * end, char ** bank, int bankSize){
    char *queue[BANK_LEN] = {0};
    char *visited[BANK_LEN + 1] = {0};
    char keys[5] = "ACGT";
    int top_q = -1;
    int top_v = -1;
    int ret = 0;

    visited[++top_v] = start;
    queue[++top_q] = start;

    while (top_q > 0) {
        char *s = queue[top_q--];
        if (strcmp(s, end) == 0)
            return ret;

        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < strlen(keys); j++) {
                char next[LEN + 1];

            }
        }

        ret++;
    }


}