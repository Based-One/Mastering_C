#include "grains.h"
#include "stdint.h"

uint64_t total(void){

	return UINT64_MAX;
}

uint64_t square(uint8_t index){
	if (index < 1 || index > 64 ) return 0;

	uint64_t out = 1;
	return out << (index-1);
}

