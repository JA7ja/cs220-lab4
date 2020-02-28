#ifndef _CHESS_H
#define _CHESS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INVALID_INDEX 0xFF

#define NORTH_OF(i) ((((i) > 63) || ((i) < 8))? INVALID_INDEX : ((i) - 8))
#define SOUTH_OF(i) ((((i) > 55) || ((i) < 0))? INVALID_INDEX : ((i) + 8))
#define EAST_OF(i) ((((i) % 8) == 0)? INVALID_INDEX : ((i) - 1))
#define WEST_OF(i) ((((i) + 1) % 8 == 0)? INVALID_INDEX : ((i) + 1))
#define SE_OF(i) (SOUTH_OF(EAST_OF(i)))
#define SW_OF(i) (SOUTH_OF(WEST_OF(i)))
#define NE_OF(i) (NORTH_OF(EAST_OF(i)))
#define NW_OF(i) (NORTH_OF(WEST_OF(i)))

#define SET_BIT(k, i) ((k) = (k) | 1UL << (i))
#define CLEAR_BIT(k, i) ((k) = (k) & ~(1UL << (i)))
#define IS_SET(k, i) ((k) & (1UL << (i)))

struct _move {
	uint8_t from;
	uint8_t to;
};
typedef struct _move Move;

extern uint64_t king_pos;

extern void display_board();
extern Move get_move();
extern unsigned int make_move(Move m);
extern uint8_t notation_to_idx(char file, char rank);

#endif
