#include "grains.h"
#include "stdint.h"

uint64_t total(void){

	uint64_t total = 2;
	for( int i = 2; i <= 64; i++){
		total *= total;

	}
	return total + 1;
}

uint64_t square(uint8_t index){
	if (index == 1 || index == 2 ) return index;
	uint64_t total = 2;
	for(int i = 2; i <= index; i++){
		total *= total;
	}

	return index + 1;
}

