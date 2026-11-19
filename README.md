Dots and Boxes is a console-based, two-player game implemented in C. The game board consists of 4 rows and 5 columns, containing a total of 20 boxes.
Project Files
The project is organized into the following files:
- main.c: Initializes the game and controls the main game loop.
- board.c: Initializes and displays the game board.
- game.c: Validates moves, detects completed boxes, updates player scores, and declares the winner.
- game.h: Contains shared constants, structures, and game function declarations.
- input.c: Reads and parses a player's move from standard input.
- input.h: Contains the input function declaration and input-buffer size.
- Makefile: Provides commands to build and run the program, as well as debugging and memory-checking targets.
Building and Running the Game
To compile the project, open the terminal in the project directory and execute make. Once compilation is complete, run the game using ./dots_and_boxes.

Alternatively, execute make run to compile and launch the game in one step.
Entering Moves
Players enter their moves using three values: orientation, row, and column.

For horizontal edges, players enter H followed by the row and column numbers. The valid row numbers range from 1 to 5, while the valid column numbers range from 1 to 5.

For vertical edges, players enter V followed by the row and column numbers. The valid row numbers range from 1 to 4, while the valid column numbers range from 1 to 6.

Examples of valid moves include H 2 3 and V 1 4. All coordinates are 1-based.

If a player enters coordinates outside the permitted range, selects an edge that has already been drawn, or provides malformed input, the move is rejected. In such cases, the game state remains unchanged, and the player keeps their turn.

When a player completes one or more boxes, they receive the corresponding points and get another turn. Otherwise, the turn passes to the other player.
Debugging with GDB
The project includes a GDB debugging target. To start the debugger, execute make debug in the terminal.

The following GDB commands can be used to inspect and debug the game:
- break make_move: Sets a breakpoint at the make_move function.
- run: Starts the program.
- print game->current_player: Displays the current player.
- next: Executes the next line of code.
- continue: Resumes program execution until the next breakpoint.
Memory Checking with Valgrind
The project also provides a Valgrind target for checking memory-related issues.

Execute make valgrind to launch the program under Valgrind. Enter moves until the game ends, or use Ctrl-D to terminate input.

The implementation uses fixed-size data structures and does not allocate dynamic memory.
Sprint 1 Scope
Sprint 1 focuses exclusively on implementing the two-player console version of Dots and Boxes.

The current implementation includes board initialization and display, move input and validation, box-completion detection, score management, turn handling, and winner declaration.


This functionality cannot be guaranteed through the C program or Makefile alone because it requires operating-system and virtual-machine configuration.

To achieve this, configure automatic login (autologin/getty) and a startup command in the selected Linux distribution after copying and testing the game inside the virtual machine.

Security implications should also be considered before enabling automatic login, particularly when using a shared or externally accessible machine.
