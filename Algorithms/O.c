// #include <stdio.h>
// #include <limits.h>
// #include <time.h>
//
// // Solución O(n^3)
// int maxSubArraySum_n3(int arr[], int n) {
//     int max_sum = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             int current_sum = 0;
//             for (int k = i; k <= j; k++) {
//                 current_sum += arr[k];
//             }
//             if (current_sum > max_sum) {
//                 max_sum = current_sum;
//             }
//         }
//     }
//     return max_sum;
// }
//
// // Solución O(n^2)
// int maxSubArraySum_n2(int arr[], int n) {
//     int max_sum = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         int current_sum = 0;
//         for (int j = i; j < n; j++) {
//             current_sum += arr[j];
//             if (current_sum > max_sum) {
//                 max_sum = current_sum;
//             }
//         }
//     }
//     return max_sum;
// }
//
// // Solución O(n) usando el algoritmo de Kadane
// int maxSubArraySum_n(int arr[], int n) {
//     int max_sum = arr[0];
//     int current_sum = arr[0];
//     for (int i = 1; i < n; i++) {
//         current_sum = (current_sum + arr[i] > arr[i]) ? current_sum + arr[i] : arr[i];
//         max_sum = (current_sum > max_sum) ? current_sum : max_sum;
//     }
//     return max_sum;
// }
// double measure_time(int (*func)(int[], int), int arr[], int n) {
//     clock_t start, end;
//     start = clock();
//     int result = func(arr, n);
//     end = clock();
//     printf("Resultado: %d\n", result);
//     return ((double)(end - start)) / CLOCKS_PER_SEC;
// }
//
// int main() {
//     int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);
//
//     printf("Tiempo O(n^3): %.6f segundos\n", measure_time(maxSubArraySum_n3, arr, n));
//     printf("Tiempo O(n^2): %.6f segundos\n", measure_time(maxSubArraySum_n2, arr, n));
//     printf("Tiempo O(n): %.6f segundos\n", measure_time(maxSubArraySum_n, arr, n));
//
//     return 0;
// }
