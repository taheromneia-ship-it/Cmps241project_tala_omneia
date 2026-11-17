# Dots and Boxes — Sprint 1

Console-based two-player Dots and Boxes in C. The board contains 4 rows by 5 columns of boxes (20 total).

## Files
- `main.c`: initializes the game and controls the game loop
- `board.c`: initializes and displays the board
- `game.c`: validates moves, detects completed boxes, updates scores, and declares the winner
- `game.h`: shared constants, structures, and game function declarations
- `input.c`: reads and parses a player's move from standard input
- `input.h`: input function declaration and input-buffer size
- `Makefile`: builds, runs, and provides GDB/Valgrind targets

## Build and run
```sh
make
./dots_and_boxes
```
Or run `make run`.

## Entering moves
Enter three values: orientation, row, column.
- `H row column`: horizontal edge. Rows are 1–5 and columns are 1–5.
- `V row column`: vertical edge. Rows are 1–4 and columns are 1–6.

Examples: `H 2 3` or `V 1 4`. Coordinates are 1-based. A move that is out of range or repeats an existing edge is rejected without changing the turn. Malformed input is also rejected.

A player who completes one or more boxes receives those boxes and takes another turn. Otherwise, the turn passes to the other player.

## Debugging with GDB
```sh
make debug
```
Useful GDB commands:
```gdb
break make_move
run
print game->current_player
next
continue
```

## Memory checking with Valgrind
```sh
make valgrind
```
Enter moves until the game ends (or use Ctrl-D to end input). The program uses fixed-size data structures and does not allocate dynamic memory.

## Sprint 1 scope
This version implements the two-player console game only. Bot functionality belongs to Sprint 2. Network programming and multithreading are not included.

## VM auto-start note
The project brief asks for the game to launch automatically after the Linux VM boots, without an interactive login. This is an OS/VM configuration task, not something the C program or Makefile can guarantee. Configure an autologin/getty and a startup command in the chosen Linux distribution after the game has been copied and tested there. Consider the security implications before enabling automatic login on a shared or exposed machine.
