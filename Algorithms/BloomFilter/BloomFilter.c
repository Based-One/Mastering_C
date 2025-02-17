// #include "BloomFilter.h"
// #include <stdarg.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
//
// #include "bitArray.h"
// #include "hashf.h"
//
// BloomFilter * bloomFilterInit(size_t size, size_t num_functions, ...) {
//     BloomFilter *filter = malloc(sizeof(BloomFilter));
//     if (filter == NULL) {
//         printf("Out of memory\n");
//         exit(EXIT_FAILURE);
//     }
//     filter->bit_array = bitArrayInit(size);
//     filter->num_functions = num_functions;
//     filter->hash32_functions = malloc(num_functions * sizeof(hash32_func));
//     if (filter->hash32_functions == NULL) {
//         printf("Out of memory\n");
//         exit(EXIT_FAILURE);
//     }
//
//     va_list args;
//     va_start(args, num_functions);
//     for (size_t i = 0; i < num_functions; ++i) {
//         filter->hash32_functions[i] = va_arg(args, hash32_func);
//     }
//     va_end(args);
//
//     filter->num_items = 0;
//
//     return filter;
// }
//
// void bloomFilterAdd(BloomFilter *filter, const void *item, size_t length) {
//     for (size_t i = 0; i < filter->num_functions; ++i) {
//         uint32_t hash = filter->hash32_functions[i](item, length);
//         size_t index = hash % filter->bit_array->size;
//         bitArraySet1(filter->bit_array, index);
//     }
//     filter->num_items++;
// }
//
// bool bloomFilterContains(const BloomFilter *filter, const void *item, size_t length) {
//     for (size_t i = 0; i < filter->num_functions; ++i) {
//         uint32_t hash = filter->hash32_functions[i](item, length);
//         size_t index = hash % filter->bit_array->size;
//         if (!bitArrayGet(filter->bit_array, index)) {
//             return false;
//         }
//     }
//     return true;
// }
//
// void bloomFilterFree(BloomFilter *filter) {
//     bitArrayFree(filter->bit_array);
//     free(filter->hash32_functions);
//     free(filter);
// }
//
// void printBits(const BitArray *bit_array) {
//     printf("Bloom Filter Bits:\n");
//     for (size_t i = 0; i < bit_array->size; i++) {
//         printf("%d", bitArrayGet(bit_array, i) ? 1 : 0);
//         if ((i + 1) % 8 == 0) {
//             printf(" "); // Print space every byte for readability
//         }
//     }
//     printf("\n");
// }
//
// // Function to print bytes of the Bloom Filter's bit array
// void printBytes(const BitArray *bit_array) {
//     size_t byte_size = (bit_array->size + 7) / 8;
//     printf("Bloom Filter Bytes:\n");
//     for (size_t i = 0; i < byte_size; i++) {
//         printf("%02X ", bit_array->mem[i]);
//     }
//     printf("\n");
// }
//
// int main() {
//     size_t bloom_size = 1000;
//     size_t num_hash_functions = 2;
//
//     BloomFilter *filter = bloomFilterInit(bloom_size, num_hash_functions, djb2, sdbm);
//
//     const char *item1 = "hello";
//     const char *item2 = "world";
//     const char *item3 = "bloom";
//     const char *item4 = "filter";
//     const char *item5 = "test";
//     printf("Before adding items\n");
// printBits(filter->bit_array);
//     bloomFilterAdd(filter, item1, strlen(item1));
//     bloomFilterAdd(filter, item2, strlen(item2));
//     bloomFilterAdd(filter, item3, strlen(item3));
//
//     printf("After adding items\n");
//     printBits(filter->bit_array);
//     printBytes(filter->bit_array);
//
//     printf("Contains 'hello': %s\n", bloomFilterContains(filter, item1, strlen(item1)) ? "true" : "false");
//     printf("Contains 'world': %s\n", bloomFilterContains(filter, item2, strlen(item2)) ? "true" : "false");
//     printf("Contains 'bloom': %s\n", bloomFilterContains(filter, item3, strlen(item3)) ? "true" : "false");
//
//     printf("Contains 'filter': %s\n", bloomFilterContains(filter, item4, strlen(item4)) ? "true" : "false");
//     printf("Contains 'test': %s\n", bloomFilterContains(filter, item5, strlen(item5)) ? "true" : "false");
//
//     bloomFilterFree(filter);
//
//     return 0;
// }