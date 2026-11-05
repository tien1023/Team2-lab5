#include "myheaders.h"

// This algorithm will sort the array in ascending order using selection sort.
void selectionSort(long data[], long size) {

    // This part is choosing each position to fill, except the last one possible
    for (long i = 0; i < size - 1; i++) {
        long minIndex = i;

        // Trying to find smallest value in section 
        for (long j = i + 1; j < size; j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }

        // Move the value we got into position i after doing the search.
        swap(data[i], data[minIndex]);
    }
}