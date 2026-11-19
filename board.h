#ifndef BOARD_H
#define BOARD_H

#define BOX_ROWS 4
#define BOX_COLS 5
#define TOTAL_BOXES (BOX_ROWS * BOX_COLS)

typedef struct {
    int horizontal[BOX_ROWS + 1][BOX_COLS];
    int vertical[BOX_ROWS][BOX_COLS + 1];
    char owner[BOX_ROWS][BOX_COLS];
} Board;

void board_init(Board *board);
void board_display(const Board *board);

#endif
