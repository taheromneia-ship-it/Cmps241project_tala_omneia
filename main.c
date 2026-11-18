#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "game.h"
#include "input.h"

int main(void)
{
    Game game;
    game_init(&game);

    printf("=== Dots and Boxes ===\n");
    printf("Two players: A and B\n");
    printf("Complete a box to score and play again.\n");
    printf("Enter moves as: row1 col1 row2 col2\n");
    printf("Example: 0 0 0 1\n");
    printf("Dot rows: 0-%d | Dot columns: 0-%d\n",
           BOX_ROWS, BOX_COLS);
    printf("Press Ctrl+D at an empty prompt to exit.\n");

    board_display(&game.board);
    game_print_scores(&game);

    while (!game_is_over(&game)) {
        Move move;

        printf("\nPlayer %c, enter your move: ",
               game.current_player);
        fflush(stdout);

        InputResult result = input_read_move(&move);

        if (result == INPUT_END) {
            if (ferror(stdin)) {
                fprintf(stderr, "\nError reading input.\n");
                return EXIT_FAILURE;
            }

            printf("\nInput ended. Game stopped.\n");
            return EXIT_SUCCESS;
        }

        if (result == INPUT_INVALID) {
            printf("Invalid input. Enter exactly four integers.\n");
            continue;
        }

        const char *error = game_validate_move(&game, &move);

        if (error != NULL) {
            printf("Invalid move: %s\n", error);
            continue;
        }

        char player = game.current_player;
        int claimed = game_apply_move(&game, &move);

        board_display(&game.board);
        game_print_scores(&game);

        if (claimed > 0) {
            printf("Player %c claimed %d box%s!\n",
                   player, claimed,
                   claimed == 1 ? "" : "es");

            if (!game_is_over(&game)) {
                printf("Player %c plays again.\n", player);
            }
        }
    }

    game_print_result(&game);
    return EXIT_SUCCESS;
}

    display_board(&game);
    display_result(&game);
    return EXIT_SUCCESS;
}
