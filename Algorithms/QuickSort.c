#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void fillArrayWithRandomNumbers(int arr[], int size, int max_value) {
    srand(time(0)); // Inicializar la semilla para generar números aleatorios
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max_value + 1); // Genera un número aleatorio entre 0 y max_value
    }
}

void fillArrayPartiallyOrderedLastElementUnsorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        arr[i] = i;
    }
    arr[size - 1] = -1; // El último elemento desordenado
}

void fillArrayPartiallyOrderedFirstElementUnsorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        arr[i] = i;
    }
    arr[0] = -1; // El primer elemento desordenado
}

void fillArrayOrdered(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

// int main() {
//     int n = 10000;
//     int arr[n];
//     clock_t start, end;
//     double cpu_time_used;
//
//     fillArrayWithRandomNumbers(arr, n, 10000);
//     start = clock();
//     quickSort(arr, 0, n - 1);
//     end = clock();
//     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Convertir a milisegundos
//     printf("QuickSort - Arreglo completamente desordenado: %f ms\n", cpu_time_used);
//
//     fillArrayPartiallyOrderedLastElementUnsorted(arr, n);
//     start = clock();
//     quickSort(arr, 0, n - 1);
//     end = clock();
//     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
//     printf("QuickSort - Último elemento desordenado: %f ms\n", cpu_time_used);
//
//     fillArrayPartiallyOrderedFirstElementUnsorted(arr, n);
//     start = clock();
//     quickSort(arr, 0, n - 1);
//     end = clock();
//     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
//     printf("QuickSort - Primer elemento desordenado: %f ms\n", cpu_time_used);
//
//     fillArrayOrdered(arr, n);
//     start = clock();
//     quickSort(arr, 0, n - 1);
//     end = clock();
//     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
//     printf("QuickSort - Arreglo completamente ordenado: %f ms\n", cpu_time_used);
//
//     return 0;
// }
