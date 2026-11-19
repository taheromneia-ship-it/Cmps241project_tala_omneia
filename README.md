# Dots and Boxes – Sprint 1

## Project Description

A console-based, two-player Dots and Boxes game implemented in C. The board consists of 4 rows and 5 columns, containing 20 boxes.

## Project Files

- **main.c:** Initializes the game and manages the main game loop.
- **board.c:** Initializes and displays the board.
- **game.c:** Handles move validation, box completion, scoring, and winner declaration.
- **game.h:** Contains shared constants, structures, and function declarations.
- **input.c / input.h:** Handle reading and parsing player moves.
- **Makefile:** Provides build, run, debug, and Valgrind commands.

## Compilation and Execution

Compile the project using:

`make`

Run the game using:

`./dots_and_boxes`

Alternatively, use `make run` to compile and run the game.

## How to Play

Enter each move using the following format:

`H row column` for horizontal edges.

`V row column` for vertical edges.

Valid coordinates:

- Horizontal: rows 1–5, columns 1–5.
- Vertical: rows 1–4, columns 1–6.

For example: `H 2 3` or `V 1 4`.

Invalid coordinates, repeated edges, and malformed inputs are rejected without changing the game state or the current player's turn.

Completing a box earns the player a point and allows them to play again. Otherwise, the turn passes to the other player.

## Debugging and Memory Checking

- `make debug` launches the program using GDB.
- `make valgrind` runs the program under Valgrind for memory checking.

The implementation uses fixed-size data structures and does not allocate dynamic memory.

## Sprint 1 Scope

Sprint 1 implements the two-player console version of the game, including board management, input validation, scoring, turn handling, and winner declaration.

Bot functionality is reserved for Sprint 2. Network programming and multithreading are not included in this sprint.

## VM Auto-Start

Automatic game execution after VM boot requires Linux configuration rather than changes to the C program. This can be configured using automatic login and a startup command in the selected Linux distribution. Security implications should be considered before enabling automatic login.
