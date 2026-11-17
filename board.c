#include <stdio.h>
#include "game.h"

void initialize_game(Game *game)
{
    int r, c;
    for (r = 0; r <= ROWS; r++)
        for (c = 0; c < COLS; c++)
            game->board.horizontal[r][c] = 0;

    for (r = 0; r < ROWS; r++)
        for (c = 0; c <= COLS; c++)
            game->board.vertical[r][c] = 0;

    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            game->board.boxes[r][c] = ' ';

    game->current_player = 'A';
    game->score_a = 0;
    game->score_b = 0;
    game->claimed_boxes = 0;
}

void display_board(const Game *game)
{
    int r, c;
    printf("\n       Dots and Boxes (4 x 5)\n\n");

    for (r = 0; r <= ROWS; r++) {
        /* Horizontal edges and dots. */
        for (c = 0; c < COLS; c++) {
            printf("  o");
            printf(game->board.horizontal[r][c] ? "-----" : "     ");
        }
        printf("  o\n");

        if (r < ROWS) {
            for (c = 0; c <= COLS; c++) {
                printf(game->board.vertical[r][c] ? "  |  " : "     ");
                if (c < COLS)
                    printf(" %c   ", game->board.boxes[r][c]);
            }
            printf("\n");
        }
    }

    printf("\nScore: Player A = %d | Player B = %d\n",
           game->score_a, game->score_b);
}
