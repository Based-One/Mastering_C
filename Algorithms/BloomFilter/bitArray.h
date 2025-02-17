#ifndef BIT_ARRAY_H
#include <stdlib.h>
#include<stdint.h>
typedef struct{
    uint32_t *mem;
    size_t size;
}BitArray;


BitArray*bitArrayInit(size_t numBits);
void bitArrayFree(BitArray*bit_array);
bool bitArrayGet(const BitArray*bit_array, size_t bitIndex);
void bitArraySet(BitArray*bit_array,size_t bitIndex,bool val);
void bitArraySet0(BitArray*bit_array,size_t bitIndex);
void bitArraySet1(BitArray*bit_array,size_t bitIndex);

#define BIT_ARRAY_H
#endif
