// #include <stdio.h>
// #include <stdlib.h>
// #define PRIME_NUM 269
// struct Node {
//     int index;
//     struct Node *next;
// };
// int hash(int value) {
//     return abs((value%PRIME_NUM));
//     }
// struct Node* initHash(struct Node *ht) {
//     ht = (struct Node*) malloc(sizeof(struct Node)*PRIME_NUM);
//     for (int i = 0; i<PRIME_NUM; i++) {
//         ht[i].index = -1;
//         ht[i].next = NULL;
//     }
//     return ht;
// }
//
//
//
//
// int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//     *returnSize = 2;
//     int *result = (int * )malloc(*returnSize * sizeof(int));
//     struct Node *ht = initHash(ht);
//     int hash_num;
//     for (int i = 0; i<PRIME_NUM; i++) {
//         hash_num = nums[i];
//         if (ht[hash_num].index == -1) {
//             ht[hash_num].index = i;
//         }
//         else {
//             struct Node *num =  malloc(sizeof(struct Node));
//             num->index = i;
//             num->next = NULL;
//             struct Node *temp = malloc(sizeof(struct Node));
//             for(;temp->next != NULL){
//                 temp = temp->next;
//                 temp->next = num;
//         }
//     for (int i = 0; i< numsSize;i++) {
//     hash_num = hash(target-nums[i]);
//     if(ht[hash_num].index == -1)
//         continue;
//         if (nums[ht[hash_num].index] == target -nums[i] && ht[hash_num].index != i) {
//
//             result[0] = i;
//             result[1] = ht[hash_num].index;
//             return result;
//
//         }
//         else {
//             struct Node *temp  = ht[hash_num].next;
//             for(;temp!= NULL) {
//                 if (nums[temp->index]== target -nums[i] && temp->index!= i) {
//                     result[0] = i;
//                     result[1] = temp->index;
//                     return result;
//
//
//                 }
//             }
//
//
//         }
//         return result;
//     }
//
//
//
//     }
// return result;
// }
// int main(void) {
//
// }
