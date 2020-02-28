#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "chess.h"

uint64_t king_pos = 0;

unsigned int make_move(Move m){
	if(IS_SET(king_pos, m.from) == 0){
		return 0;
	}

	if(!(m.to == NORTH_OF(m.from) || m.to == SOUTH_OF(m.from) || m.to == EAST_OF(m.from) || m.to == WEST_OF(m.from) || m.to == SE_OF(m.from) || m.to == SW_OF(m.from) || m.to == NE_OF(m.from) || m.to == NW_OF(m.from))){
		return 0;
	}

	CLEAR_BIT(king_pos, m.from);
	SET_BIT(king_pos, m.to);

	return 1;
}

int main(){
	char s[128];
	uint8_t index;
	unsigned int error;
	Move m = {INVALID_INDEX, INVALID_INDEX};

	printf("Enter initial king position: ");
	fgets(s, 127, stdin);
	index = notation_to_idx(s[0], s[1]);
	if(index == INVALID_INDEX){
		printf("%d", error);
		exit(error);
	}

	SET_BIT(king_pos, index);

	display_board();

	for(;;){
		m = get_move();

		if(make_move(m) != 1) {
			printf("Invalid move. Try again!\n");
		}else{
			display_board();
		}
	}

	return 0;
}
