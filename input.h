#ifndef INPUT_H
#define INPUT_H

#include "game.h"

typedef enum {
    INPUT_END,
    INPUT_OK,
    INPUT_INVALID
} InputResult;

InputResult input_read_move(Move *move);

#endif
