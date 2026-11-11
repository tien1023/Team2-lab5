#include "myheaders.h"
#include <cstddef>
#include <limits>
#include <utility>
#include <vector>

// Hi this is a radix sorting algorithm
// It sorts the first 'size' values in ascending order, one byte at a time

void radixSort(long data[], long size) {
    // Empty arrays and single values are already sorted.
    if (size < 2) {
        return;
    }

    constexpr unsigned int bitsPerByte = 8;
    constexpr std::size_t bucketCount = 256;

    constexpr unsigned int totalBits =
        std::numeric_limits<unsigned long>::digits;

    static_assert(totalBits % bitsPerByte == 0, "Total bits must be a multiple of bits per byte.");

    // Here we set up a mask so negative values can be analyzed before positive values.
    constexpr unsigned long signMask = 1UL << (totalBits - 1);

    // Here we are allocating temporary storage for the sorting passes 
    std::vector<long> tmp(static_cast<std::size_t>(size));

    // Using pointers to track where each pass reads and writes the values.
    long* source = data;
    long* destination = tmp.data();

    // Here we sorting one byte at a time, starting with the lowest 
    for (unsigned int shift = 0; shift < totalBits;
         shift += bitsPerByte) {

        // Here we are setting all 256 counters to zero for this pass.
        std::size_t count[bucketCount] = {};

        // Here we count how many values belong in each byte bucket.
        for (long i = 0; i < size; i++) {
            unsigned long key =
                static_cast<unsigned long>(source[i]) ^ signMask;

            std::size_t bucket = (key >> shift) & 255UL;
            count[bucket]++;
        }

        // Here we convert the frequencies into starting postiion
        std::size_t nextPosition = 0;

        //Bucket vode =)
        for (std::size_t bucket = 0; bucket < bucketCount; bucket++) {
            std::size_t frequency = count[bucket];
            count[bucket] = nextPosition;
            nextPosition += frequency;
        }

        // Here we place each value into its bucket and keep the order
        for (long i = 0; i < size; i++) {
            unsigned long key =
                static_cast<unsigned long>(source[i]) ^ signMask;

            std::size_t bucket = (key >> shift) & 255UL;
            destination[count[bucket]] = source[i];

            // Here we move to the next open spot in the same bucket.
            count[bucket]++;
        }

        // Make ouput -> input for next pass
        std::swap(source, destination);
    }

    // Here we copy the organized values back if for some reason they're in temp storage
    if (source != data) {
        for (long i = 0; i < size; i++) {
            data[i] = source[i];
        }
    }

  
}