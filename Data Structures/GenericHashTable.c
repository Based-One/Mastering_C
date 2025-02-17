// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
//
// #define MAX_KEY_SPACE 10
// #define MAX_HASH_SIZE 10
//
// typedef struct {
//     void* data;
//     char key[MAX_KEY_SPACE];
// } HashTableEntry;
//
// typedef struct {
//     HashTableEntry* entries[MAX_HASH_SIZE];
//     unsigned int (*hash_func)(const char* key);
//     int (*cmp_func)(const char* key1, const char* key2);
// } HashTable;
//
// typedef struct {
//     char name[MAX_KEY_SPACE];
//     int age;
// } Person;
//
// unsigned int defaultHash(const char* key) {
//     int length = strnlen(key, MAX_KEY_SPACE);
//     unsigned int hash_value = 0;
//     for (int i = 0; i < length; ++i) {
//         hash_value += key[i];
//         hash_value += hash_value * key[i] % (MAX_HASH_SIZE - 1);
//     }
//     return hash_value % MAX_HASH_SIZE;
// }
//
// int defaultCompare(const char* key1, const char* key2) {
//     return strcmp(key1, key2);
// }
//
// void initHashTable(HashTable* table, unsigned int (*hash_func)(const char*), int (*compare_func)(const char*, const char*)) {
//     for (int i = 0; i < MAX_HASH_SIZE; ++i) {
//         table->entries[i] = NULL;
//     }
//     table->hash_func = hash_func ? hash_func : defaultHash;
//     table->cmp_func = compare_func ? compare_func : defaultCompare;
// }
//
// bool hashInsert(HashTable* table, void* data, const char* key) {
//     int index = table->hash_func(key);
//     int startIndex = index;
//
//     while (table->entries[index] != NULL) {
//         if (table->cmp_func(table->entries[index]->key, key) == 0) {
//             return false;  // Duplicate key; insertion fails
//         }
//         index = (index + 1) % MAX_HASH_SIZE;  // Linear probing
//         if (index == startIndex) return false; // Table is full
//     }
//
//     HashTableEntry* newEntry = malloc(sizeof(HashTableEntry));
//     if (!newEntry) return false;
//     newEntry->data = data;
//     strncpy(newEntry->key, key, MAX_KEY_SPACE - 1);
//     newEntry->key[MAX_KEY_SPACE - 1] = '\0';
//     table->entries[index] = newEntry;
//     return true;
// }
//
// void* hashLookUp(HashTable* table, const char* key) {
//     int index = table->hash_func(key);
//     int startIndex = index;
//
//     while (table->entries[index] != NULL) {
//         if (table->cmp_func(table->entries[index]->key, key) == 0) {
//             return table->entries[index]->data;
//         }
//         index = (index + 1) % MAX_HASH_SIZE;  // Linear probing
//         if (index == startIndex) break;  // Full circle, not found
//     }
//     return NULL;
// }
//
// void printTable(HashTable* table) {
//     printf("\nHash Table Contents:\n");
//     for (int i = 0; i < MAX_HASH_SIZE; ++i) {
//         if (table->entries[i] == NULL) {
//             printf("\t%i\t----\n", i);
//         } else {
//             Person* person = table->entries[i]->data;
//             printf("\t%i\tKey: %s\tName: %s\tAge: %d\n", i, table->entries[i]->key, person->name, person->age);
//         }
//     }
// }
//
// int main() {
//     HashTable table;
//     initHashTable(&table, defaultHash, defaultCompare);
//
//     // Define test persons
//     Person alice = { .name = "Alice", .age = 22 };
//     Person bob = { .name = "Bob", .age = 30 };
//     Person charlie = { .name = "Charlie", .age = 25 };
//     Person dave = { .name = "Dave", .age = 28 };
//     Person eve = { .name = "Eve", .age = 35 };
//     Person frank = { .name = "Frank", .age = 40 };
//     Person grace = { .name = "Grace", .age = 19 };
//     Person heidi = { .name = "Heidi", .age = 45 };
//     Person ivan = { .name = "Ivan", .age = 50 };
//     Person judy = { .name = "Judy", .age = 55 };
//
//     // Test Case 1: Insert distinct keys
//     printf("Inserting unique keys:\n");
//     hashInsert(&table, &alice, alice.name);
//     hashInsert(&table, &bob, bob.name);
//     hashInsert(&table, &charlie, charlie.name);
//     hashInsert(&table, &dave, dave.name);
//     printTable(&table);
//
//     // Test Case 2: Insert duplicate key (should fail)
//     printf("\nInserting duplicate key (Alice):\n");
//     bool result = hashInsert(&table, &eve, "Alice");
//     printf("Insert result for duplicate key 'Alice': %s\n", result ? "Success" : "Failure");
//     printTable(&table);
//
//     // Test Case 3: Insert more unique keys to fill the table and handle collisions
//     printf("\nInserting more unique keys (including collision handling):\n");
//     hashInsert(&table, &eve, eve.name);
//     hashInsert(&table, &frank, frank.name);
//     hashInsert(&table, &grace, grace.name);
//     hashInsert(&table, &heidi, heidi.name);
//     hashInsert(&table, &ivan, ivan.name);
//     hashInsert(&table, &judy, judy.name);
//     printTable(&table);
//
//     // Test Case 4: Lookup existing key
//     printf("\nLooking up existing key 'Charlie':\n");
//     Person* p = hashLookUp(&table, "Charlie");
//     if (p) {
//         printf("Found: %s, Age: %d\n", p->name, p->age);
//     } else {
//         printf("Not found\n");
//     }
//
//     // Test Case 5: Lookup non-existing key
//     printf("\nLooking up non-existing key 'Zara':\n");
//     p = hashLookUp(&table, "Zara");
//     if (p) {
//         printf("Found: %s, Age: %d\n", p->name, p->age);
//     } else {
//         printf("Not found\n");
//     }
//
//     // Test Case 6: Inserting more than MAX_HASH_SIZE items (should handle full table gracefully)
//     printf("\nAttempting to insert beyond table capacity:\n");
//     Person extra = { .name = "Extra", .age = 60 };
//     result = hashInsert(&table, &extra, extra.name);
//     printf("Insert result for 'Extra': %s\n", result ? "Success" : "Failure");
//     printTable(&table);
//
//     // Clean up memory
//     for (int i = 0; i < MAX_HASH_SIZE; ++i) {
//         free(table.entries[i]);
//     }
//
//     return 0;
// }
