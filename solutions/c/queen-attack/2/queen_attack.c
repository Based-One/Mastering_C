#include "queen_attack.h"


attack_status_t attack_status[] = {CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION};
position_t queen_1;
position_t queen_2;
attack_status_t can_attack(position_t queen_1, position_t queen_2){
	if(queen_1.row == queen_2.row && queen_1.column == queen_2.column) return attack_status[2];
	if(queen_1.row == queen_2.row || queen_1.column == queen_2.column) return attack_status[1];
	int check_row = queen_1.row - queen_2.row;
	int check_column = queen_1.column - queen_2.column;
	if(check_row * -1 == check_column * -1){
		return attack_status[1];
	}
	else if(check_row != check_column){
		return attack_status[0];

	}
	else{
	return attack_status[2];

	}
	
	
}	
