#include <ctype.h>
#include <stdio.h>
#include "game.h"

static int box_is_complete(const Board *board, int row, int col)
{
    return board->horizontal[row][col] &&
           board->horizontal[row + 1][col] &&
           board->vertical[row][col] &&
           board->vertical[row][col + 1];
}

void display_instructions(void)
{
    printf("How to enter a move:\n");
    printf("  H row column  - draw a horizontal line\n");
    printf("  V row column  - draw a vertical line\n\n");
    printf("Coordinates are 1-based.\n");
    printf("Horizontal: rows 1-%d, columns 1-%d.\n", ROWS + 1, COLS);
    printf("Vertical:   rows 1-%d, columns 1-%d.\n\n", ROWS, COLS + 1);
    printf("Example: H 2 3 draws the horizontal edge on row 2, column 3.\n");
    printf("         V 1 4 draws the vertical edge on row 1, column 4.\n\n");
}

/* Returns the number of newly completed boxes, or -1 for an invalid move. */
int make_move(Game *game, char orientation, int row, int col)
{
    int r = row - 1;
    int c = col - 1;
    int completed = 0;
    char type = (char)toupper((unsigned char)orientation);

    if (type == 'H') {
        if (row < 1 || row > ROWS + 1 || col < 1 || col > COLS)
            return -1;
        if (game->board.horizontal[r][c])
            return -1;
        game->board.horizontal[r][c] = 1;

        if (r > 0 && game->board.boxes[r - 1][c] == ' ' &&
            box_is_complete(&game->board, r - 1, c)) {
            game->board.boxes[r - 1][c] = game->current_player;
            completed++;
        }
        if (r < ROWS && game->board.boxes[r][c] == ' ' &&
            box_is_complete(&game->board, r, c)) {
            game->board.boxes[r][c] = game->current_player;
            completed++;
        }
    } else if (type == 'V') {
        if (row < 1 || row > ROWS || col < 1 || col > COLS + 1)
            return -1;
        if (game->board.vertical[r][c])
            return -1;
        game->board.vertical[r][c] = 1;

        if (c > 0 && game->board.boxes[r][c - 1] == ' ' &&
            box_is_complete(&game->board, r, c - 1)) {
            game->board.boxes[r][c - 1] = game->current_player;
            completed++;
        }
        if (c < COLS && game->board.boxes[r][c] == ' ' &&
            box_is_complete(&game->board, r, c)) {
            game->board.boxes[r][c] = game->current_player;
            completed++;
        }
    } else {
        return -1;
    }

    if (game->current_player == 'A')
        game->score_a += completed;
    else
        game->score_b += completed;
    game->claimed_boxes += completed;
    return completed;
}

int game_is_over(const Game *game)
{
    return game->claimed_boxes == ROWS * COLS;
}

void display_result(const Game *game)
{
    printf("\n========== FINAL RESULT ==========\n");
    printf("Player A: %d boxes\n", game->score_a);
    printf("Player B: %d boxes\n", game->score_b);
    if (game->score_a > game->score_b)
        printf("Player A wins!\n");
    else if (game->score_b > game->score_a)
        printf("Player B wins!\n");
    else
        printf("The game is a draw!\n");
}
