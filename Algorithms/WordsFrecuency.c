// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
//
// #define TABLE_SIZE 100
//
// typedef struct Node {
//     char* word;
//     int count;
//     struct Node* next;
// } Node;
//
// // Tabla hash
// Node* hashTable[TABLE_SIZE] = { NULL };
//
// // Función hash
// unsigned int hash(const char* word) {
//     unsigned int hashValue = 0;
//     while (*word) {
//         hashValue = (hashValue * 31 + *word) % TABLE_SIZE;
//         word++;
//     }
//     return hashValue;
// }
//
// void insertWord(const char* word) {
//     unsigned int index = hash(word);
//
//     // Buscar en la lista enlazada si la palabra ya existe
//     Node* current = hashTable[index];
//     while (current != NULL) {
//         if (strcmp(current->word, word) == 0) {
//             current->count++;
//             return;
//         }
//         current = current->next;
//     }
//
//     Node* newNode = malloc(sizeof(Node));
//     newNode->word = strdup(word);
//     newNode->count = 1;
//     newNode->next = hashTable[index];
//     hashTable[index] = newNode;
// }
//
// // Mostrar la tabla hash
// void displayHashTable() {
//     for (int i = 0; i < TABLE_SIZE; i++) {
//         Node* current = hashTable[i];
//         while (current != NULL) {
//             printf("%s: %d\n", current->word, current->count);
//             current = current->next;
//         }
//     }
// }
//
// // Liberar memoria de la tabla hash
// void freeHashTable() {
//     for (int i = 0; i < TABLE_SIZE; i++) {
//         Node* current = hashTable[i];
//         while (current != NULL) {
//             Node* temp = current;
//             current = current->next;
//             free(temp->word);
//             free(temp);
//         }
//     }
// }
//
// // Función para dividir el texto en palabras
// void splitAndInsertWords(const char* text) {
//     char* copy = strdup(text);
//     char* token = strtok(copy, " ");
//     while (token != NULL) {
//         for (char* p = token; *p; p++) {
//             *p = tolower(*p);
//         }
//         insertWord(token);
//         token = strtok(NULL, " ");
//     }
//     free(copy);
// }
//
// int main() {
//     const char* text = "la programacion es divertida la programacion es facil programacion";
//
//     splitAndInsertWords(text);
//
//     printf("Frecuencia de palabras:\n");
//     displayHashTable();
//
//     freeHashTable();
//
//     return 0;
// }
