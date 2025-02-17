#include "bitArray.h"
#include <stdint.h>
#include<stdio.h>
#include <limits.h>
#include <wchar.h>

BitArray * bitArrayInit(size_t num_bits) {
    BitArray *bit_array = malloc(sizeof(BitArray));
    if (bit_array == NULL) {
        printf("Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    size_t mem_size = num_bits/CHAR_BIT;
    if (num_bits%CHAR_BIT)
        mem_size++;
    bit_array->mem = calloc(mem_size,sizeof(bit_array->mem));
    if (bit_array->mem == NULL) {
        printf("out of memory");
        exit(EXIT_FAILURE);
    }
    bit_array->size = num_bits;
    return bit_array;
}
void bitArrayFree(BitArray *bit) {
    free(bit->mem);
    free(bit);
}
bool bitArrayGet(const BitArray *bit_array, size_t bitIndex) {
    if(bitIndex>bit_array->size) {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    size_t chunkOffset = bitIndex/CHAR_BIT;
    size_t bitOffset = bitIndex & (CHAR_BIT-1);
    uint32_t byte = bit_array->mem[chunkOffset];
    return (byte>>bitOffset) & 1;

}
void bitArraySet(BitArray *bit_array, size_t bitIndex,bool val) {
    if (bitIndex >= bit_array->size) {
        printf("Out of bounds");
        exit(EXIT_FAILURE);
    }
    size_t chunkOffset = bitIndex/CHAR_BIT;
    size_t bitOffset = bitIndex & (CHAR_BIT -1);


    uint32_t *byte = &(bit_array->mem[chunkOffset]);
    if(val) {
        *byte |= ((uint32_t)1)<<bitOffset;

    }
    else {
        *byte &= ~(1<<bitOffset);
    }
}
void bitArraySet1(BitArray *bit_array, size_t bitIndex) {
    bitArraySet(bit_array,bitIndex,true);
}
void bitArraySet0(BitArray *bit_array,size_t bitIndex) {
    bitArraySet(bit_array,bitIndex,false);

}
