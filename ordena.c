#include "libs&def.h"

// Swap function
void swap(Carta* a, Carta* b) {
    Carta temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(Carta arr[], int low, int high) {
    Carta pivot = arr[high];  // Choosing the last element as the pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].valor < pivot.valor || (arr[j].valor == pivot.valor && arr[j].naipe < pivot.naipe)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(Carta arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partitioning index

        quickSort(arr, low, pi - 1);  // Sorting the left side of the partition
        quickSort(arr, pi + 1, high);  // Sorting the right side of the partition
    }
}



void selectionSort(Carta arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int minIndex = i;
        int maxIndex = i;
        
        for (int j = i + 1; j < n - i; j++) {
            if (arr[j].valor < arr[minIndex].valor || (arr[j].valor == arr[minIndex].valor && arr[j].naipe < arr[minIndex].naipe)) {
                minIndex = j;
            }
            
            if (arr[j].valor > arr[maxIndex].valor || (arr[j].valor == arr[maxIndex].valor && arr[j].naipe > arr[maxIndex].naipe)) {
                maxIndex = j;
            }
        }
        
        if (minIndex != i) {
            Carta temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        
        if (maxIndex == i) {
            maxIndex = minIndex;
        }
        
        if (maxIndex != n - i - 1) {
            Carta temp = arr[n - i - 1];
            arr[n - i - 1] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}



void insertionSort(Carta arr[], int n) {
    for (int i = 1; i < n; i++) {
        Carta key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && (arr[j].valor > key.valor || (arr[j].valor == key.valor && arr[j].naipe > key.naipe))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
    }
}
