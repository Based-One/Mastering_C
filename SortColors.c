// #include <stdio.h>
//
// void swap(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int partition (int arr[], int low, int high){
//     int pivot = arr[high];
//     int i = low -1 ;
//     for (int j = low; j <= high-1; j++) {
//         if (arr[j]<= pivot) {
//             i++;
//             swap(&arr[i],&arr[j]);
//         }
//     }
//     swap(&arr[i+1],&arr[high]);
//     return (i+1);
// }
// void quickSort(int arr[],int low, int high) {
//     if (low<high) {
//         int pi = partition(arr,low,high);
//         quickSort(arr,low, pi-1);
//         quickSort(arr,pi+1,high);
//     }
// }
//      void printArray(int arr[], const int size){
//          for (int i = 0; i < size; i++) {
//              printf("%d ", arr[i]);
//          }
//          printf("\n");
//      }
// void sortColors(int* nums, int numsSize) {
//     quickSort(nums,0,numsSize-1);
//     printArray(nums,numsSize);
// }
// int main() {
//     int nums[] = {2,0,2,1,1,0};
//     sortColors(nums,6);
//     return 0;
// }