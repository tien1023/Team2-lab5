#include "myheaders.h"

// Here this algorithm will sort the array in ascending order using selection sort.
void selectionSort(long data[], long size) {

    // This part is choosing each position to fill, except the last one 
    for (long i = 0; i < size - 1; i++) {
        long minIndex = i;

        // Here we are trying to find the smallest value in the remaining section
        for (long j = i + 1; j < size; j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }

        // We are moving the value we got into position i after doing the search.
        swap(data[i], data[minIndex]);
    }
}