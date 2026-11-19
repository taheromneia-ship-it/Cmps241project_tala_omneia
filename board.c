#include <stdio.h>
#include "board.h"

void board_init(Board *board)
{
    *board = (Board){0};

    for (int r = 0; r < BOX_ROWS; r++) {
        for (int c = 0; c < BOX_COLS; c++) {
            board->owner[r][c] = ' ';
        }
    }
}

void board_display(const Board *board)
{
    printf("\n    ");

    for (int c = 0; c <= BOX_COLS; c++) {
        printf("%-4d", c);
    }

    printf("\n");

    for (int r = 0; r <= BOX_ROWS; r++) {
        printf("%2d  ", r);

        for (int c = 0; c < BOX_COLS; c++) {
            printf(".");
            printf("%s",
                   board->horizontal[r][c] ? "---" : "   ");
        }

        printf(".\n");

        if (r < BOX_ROWS) {
            printf("    ");

            for (int c = 0; c < BOX_COLS; c++) {
                printf("%c %c ",
                       board->vertical[r][c] ? '|' : ' ',
                       board->owner[r][c]);
            }

            printf("%c\n",
                   board->vertical[r][BOX_COLS] ? '|' : ' ');
        }
    }

    printf("\n");
}
