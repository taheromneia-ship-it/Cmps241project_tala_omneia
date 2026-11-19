#include <stdio.h>
#include <stdlib.h>
#include "game.h"

static int minimum(int a, int b)
{
    return a < b ? a : b;
}

static int dot_in_bounds(int row, int col)
{
    return row >= 0 && row <= BOX_ROWS &&
           col >= 0 && col <= BOX_COLS;
}

/*
 * Claims a box if it exists, is unclaimed,
 * and has all four surrounding edges.
 */
static int claim_box(Board *board, int row, int col,
                     char player)
{
    if (row < 0 || row >= BOX_ROWS ||
        col < 0 || col >= BOX_COLS) {
        return 0;
    }

    if (board->owner[row][col] != ' ') {
        return 0;
    }

    if (board->horizontal[row][col] &&
        board->horizontal[row + 1][col] &&
        board->vertical[row][col] &&
        board->vertical[row][col + 1]) {
        board->owner[row][col] = player;
        return 1;
    }

    return 0;
}

void game_init(Game *game)
{
    board_init(&game->board);
    game->current_player = 'A';
    game->score_a = 0;
    game->score_b = 0;
}

const char *game_validate_move(const Game *game,
                               const Move *move)
{
    if (!dot_in_bounds(move->r1, move->c1) ||
        !dot_in_bounds(move->r2, move->c2)) {
        return "Coordinates are outside the board.";
    }

    /*
     * Bounds are checked first, so these subtractions
     * and array accesses are safe.
     */
    int row_distance = abs(move->r1 - move->r2);
    int col_distance = abs(move->c1 - move->c2);

    if (row_distance + col_distance != 1) {
        return "Choose two adjacent horizontal or vertical dots.";
    }

    if (move->r1 == move->r2) {
        int col = minimum(move->c1, move->c2);

        if (game->board.horizontal[move->r1][col]) {
            return "That line has already been drawn.";
        }
    } else {
        int row = minimum(move->r1, move->r2);

        if (game->board.vertical[row][move->c1]) {
            return "That line has already been drawn.";
        }
    }

    return NULL;
}

int game_apply_move(Game *game, const Move *move)
{
    int claimed = 0;

    if (move->r1 == move->r2) {
        int row = move->r1;
        int col = minimum(move->c1, move->c2);

        game->board.horizontal[row][col] = 1;

        /* Check the boxes above and below the edge. */
        claimed += claim_box(&game->board, row - 1, col,
                             game->current_player);
        claimed += claim_box(&game->board, row, col,
                             game->current_player);
    } else {
        int row = minimum(move->r1, move->r2);
        int col = move->c1;

        game->board.vertical[row][col] = 1;

        /* Check the boxes to the left and right. */
        claimed += claim_box(&game->board, row, col - 1,
                             game->current_player);
        claimed += claim_box(&game->board, row, col,
                             game->current_player);
    }

    if (game->current_player == 'A') {
        game->score_a += claimed;
    } else {
        game->score_b += claimed;
    }

    /* Completing a box gives the player another turn. */
    if (claimed == 0) {
        game->current_player =
            game->current_player == 'A' ? 'B' : 'A';
    }

    return claimed;
}

int game_is_over(const Game *game)
{
    return game->score_a + game->score_b == TOTAL_BOXES;
}

void game_print_scores(const Game *game)
{
    printf("Player A: %d | Player B: %d\n",
           game->score_a, game->score_b);
}

void game_print_result(const Game *game)
{
    printf("\nGame over!\n");
    game_print_scores(game);

    if (game->score_a > game->score_b) {
        printf("Player A wins!\n");
    } else if (game->score_b > game->score_a) {
        printf("Player B wins!\n");
    } else {
        printf("The game is a draw!\n");
    }
}
