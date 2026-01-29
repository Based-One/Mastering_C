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
	if (index < 1 || index > 64 ) return 0;

	uint64_t out = 1;
	return out << (index-1);
}

