#include "myheaders.h"
//Adding as bug fix
#include <iostream>
#include <new>

// Hi this is a counting sorting algorithm
// It sorts the first 'size' values in ascending order using counting sort

void countingSort(long data[], long size) {
    // Empty arrays and single values are already sorted.
    if (size < 2) {
        return;
    }

    // Declaring the pointers where the rest of the function can access them.
    long* count = nullptr;
    long* tmp = nullptr;

    long smallest = data[0];
    long largest = data[0];

    // Find the smallest and largest values, so we can have right amount of counters
    for (long i = 1; i < size; i++) {
        if (data[i] < smallest) {
            smallest = data[i];
        }

        if (data[i] > largest) {
            largest = data[i];
        }
    }

    // Here we are allocating zero-initialized counters and temporary output storage
    long range = largest - smallest + 1;
    count = new long[range]();
    tmp = new long[size];

    // Here we count how many times each value appears
    for (long i = 0; i < size; i++) {
        count[data[i] - smallest]++;
    }

    // Here we are converting the frequency into running totals
    // And the total tells us how many values are <= this value
    for (long i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Here we are working backward through the input and placing each value in tmp
    for (long i = size - 1; i >= 0; i--) {
        long counterIndex = data[i] - smallest;

        tmp[count[counterIndex] - 1] = data[i];

        // Here we keep the matching spot open for another value of the same amount.
        count[counterIndex]--;
    }

    // Here we copy the sorted values  into the original array.
    for (long i = 0; i < size; i++) {
        data[i] = tmp[i];
    }

    // Release both dynamically allocated arrays.
    delete[] count;
    delete[] tmp;
}