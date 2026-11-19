#ifndef GAME_H
#define GAME_H

#include "board.h"

typedef struct {
    int r1;
    int c1;
    int r2;
    int c2;
} Move;

typedef struct {
    Board board;
    char current_player;
    int score_a;
    int score_b;
} Game;

void game_init(Game *game);

/*
 * Returns NULL if the move is valid.
 * Otherwise returns an error message.
 */
const char *game_validate_move(const Game *game,
                               const Move *move);

/*
 * Applies a validated move.
 * Returns the number of boxes claimed: 0, 1, or 2.
 */
int game_apply_move(Game *game, const Move *move);

int game_is_over(const Game *game);
void game_print_scores(const Game *game);
void game_print_result(const Game *game);

#endif
