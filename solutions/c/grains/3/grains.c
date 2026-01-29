#include "grains.h"
#include "stdint.h"

uint64_t total(void){
    return UINT64_MAX;
}

uint64_t square(uint8_t index){
	if (index == 1 || index == 2 || index ==0) return index;
	uint64_t total = 2;
	for(int i = 2; i < index; i++){
		total += total;
	}

	return total;
}

