#include <stdio.h>

int countBattleships(char** board, int boardSize, int* boardColSize)
{
    int ret = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            char c = *(*(board + i) + j);

            if (c == '.')
                continue;

            if (i > 0 && *(*(board + i - 1) + j) == 'X')
                continue;

            if (j > 0 && *(*(board + i) + j - 1) == 'X')
                continue;

            ret++;
        }
    }

    return ret;
}