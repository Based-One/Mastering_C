// #include <stdio.h>
// #include <string.h>
// #define MAX_NAME 256
// #define MAX_HASH 10
// typedef struct {
//     char name[MAX_NAME];
//     int age;
// }Person;
// // typedef struct {
// //     void* data;
// //     void* data;
// // }HashTable;
// Person * hash_table[MAX_HASH];
//
// unsigned int hash(const char* name) {
//     int length = strnlen(name,MAX_NAME);
//     unsigned int hash_value = 0;
//     for (int i = 0; i<length;i++) {
//         hash_value +=   name[i];
//         hash_value = (hash_value*name[i]) % MAX_HASH;
//     }
//     return hash_value;
//
//
// }
// void initHashTable () {
//     for (int i = 0; i < MAX_HASH; ++i) {
//         hash_table[i] == NULL;
//     }
//
// }
// void printTable() {
//     for (int i = 0; i < MAX_HASH; ++i) {
//         if (hash_table[i] == NULL) {
//             printf("\t%i\t----\n");
//         }
//         else {
//             printf("\t%i\t%s\n",i, hash_table[i]->name);
//         }
//     }
// }
// bool hasInsertWithKey(Person *p,char* key) {
//
//     if (p == NULL) return false;
//     int index = hash(p->name);
//     if (hash_table[index]!= NULL) {
//         return false;
//     }
// }
// bool hashInsertRandom(Person *p) {
//     if(p == NULL) return false;
//         int index = hash(p->name);
// if (hash_table[index] != NULL) {
//     return false;
// }
//     hash_table[index] = p;
//     return true;
// }
//
//
//
//
//
// int main() {
// printf("Jacob=>%u\n",hash("Jacob"));
//     printf("Juan=> %u\n",hash("Juan"));
//     Person torres = {.name = "Torres",.age = 19 };
//     Person rogers ={.name = "Rogers",.age = 19};
//     hashInsertRandom(&torres);
//     hashInsertRandom(&rogers);
//     printTable();
//
//     return 0;
// }
