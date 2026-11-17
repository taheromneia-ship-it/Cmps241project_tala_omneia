#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "game.h"

int main(void)
{
    Game game;
    char line[INPUT_SIZE];

    initialize_game(&game);
    printf("=================================\n");
    printf("       TWO-PLAYER DOTS & BOXES\n");
    printf("=================================\n\n");
    display_instructions();

    while (!game_is_over(&game)) {
        char orientation;
        int row, col;
        int completed;
        int parsed;

        display_board(&game);
        printf("Player %c, enter your move (for example H 2 3): ",
               game.current_player);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("\nInput ended. Exiting game.\n");
            return EXIT_SUCCESS;
        }

        parsed = sscanf(line, " %c %d %d", &orientation, &row, &col);
        if (parsed != 3) {
            printf("Invalid input. Enter a letter (H/V), row, and column.\n");
            continue;
        }

        completed = make_move(&game, orientation, row, col);
        if (completed < 0) {
            printf("Invalid move: check the coordinates and make sure the line is unused.\n");
            continue;
        }

        if (completed > 0) {
            printf("Player %c completed %d box(es) and gets another turn!\n",
                   game.current_player, completed);
        } else {
            game.current_player = (game.current_player == 'A') ? 'B' : 'A';
        }
    }

    display_board(&game);
    display_result(&game);
    return EXIT_SUCCESS;
}
