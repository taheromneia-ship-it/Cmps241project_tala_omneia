#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

InputResult input_read_move(Move *move)
{
    char line[256];

    if (fgets(line, sizeof line, stdin) == NULL) {
        return INPUT_END;
    }

    /*
     * If the input did not fit in the buffer,
     * discard the remainder of the line.
     */
    if (strchr(line, '\n') == NULL && !feof(stdin)) {
        int ch = getchar();

        if (ch != '\n' && ch != EOF) {
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Discard excess input. */
            }

            return INPUT_INVALID;
        }
    }

    int values[4];
    char *cursor = line;

    for (int i = 0; i < 4; i++) {
        while (isspace((unsigned char)*cursor)) {
            cursor++;
        }

        errno = 0;
        char *end;
        long value = strtol(cursor, &end, 10);

        if (cursor == end ||
            errno == ERANGE ||
            value < INT_MIN ||
            value > INT_MAX) {
            return INPUT_INVALID;
        }

        /* Each number must end at whitespace or end of input. */
        if (*end != '\0' &&
            !isspace((unsigned char)*end)) {
            return INPUT_INVALID;
        }

        values[i] = (int)value;
        cursor = end;
    }

    while (isspace((unsigned char)*cursor)) {
        cursor++;
    }

    /* Reject extra numbers or text. */
    if (*cursor != '\0') {
        return INPUT_INVALID;
    }

    *move = (Move){
        values[0], values[1], values[2], values[3]
    };

    return INPUT_OK;
}
