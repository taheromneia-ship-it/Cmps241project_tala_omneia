#include <stdio.h>
#include "input.h"

int read_move(char *orientation, int *row, int *col)
{
    char line[INPUT_SIZE];

    if (fgets(line, sizeof(line), stdin) == NULL)
        return -1;

    if (sscanf(line, " %c %d %d", orientation, row, col) != 3)
        return 0;

    return 1;
}
