#ifndef BLOOM_H
#define BLOOM_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bitArray.h"

#define HASH32_NUM_FUNCTIONS 3

typedef uint32_t (*hash32_func)(const void *data, size_t length);

typedef struct {
    BitArray *bit_array;
    hash32_func *hash32_functions;
    size_t num_functions;
    size_t num_items;
} BloomFilter;

BloomFilter *bloomFilterInit(size_t size, size_t num_functions, ...);
void bloomFilterAdd(BloomFilter *filter, const void *item, size_t length);
bool bloomFilterContains(const BloomFilter *filter, const void *item, size_t length);
void bloomFilterFree(BloomFilter *filter);

#endif /* BLOOM_H */
