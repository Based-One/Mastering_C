#include "queen_attack.h"
#include <stddef.h>

attack_status_t attack_status[] = {CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION};
attack_status_t can_attack(position_t queen_1, position_t queen_2){
	if(queen_1.row > 7   ||queen_1.column > 7 || queen_2.column == 7 || queen_2.row == 7 ) return attack_status[2];

	if(queen_1.row == queen_2.row && queen_1.column == queen_2.column) return attack_status[2];
	if(queen_1.row == queen_2.row || queen_1.column == queen_2.column) return attack_status[1];
	int check_row = queen_1.row - queen_2.row;
	int check_column = queen_1.column - queen_2.column;
	if(check_row  == check_column){
		return attack_status[1];
	}
	else if(check_row != check_column){
		return attack_status[0];

	}
	else{
	return attack_status[2];

	}
	
	
}	
