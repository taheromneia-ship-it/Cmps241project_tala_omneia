#ifndef GAME_H
#define GAME_H

#define ROWS 4
#define COLS 5
#define INPUT_SIZE 128

typedef struct {
    int horizontal[ROWS + 1][COLS];
    int vertical[ROWS][COLS + 1];
    char boxes[ROWS][COLS];
} Board;

typedef struct {
    Board board;
    char current_player;
    int score_a;
    int score_b;
    int claimed_boxes;
} Game;

void initialize_game(Game *game);
void display_board(const Game *game);
int make_move(Game *game, char orientation, int row, int col);
int game_is_over(const Game *game);
void display_result(const Game *game);
void display_instructions(void);

#endif
