// Phase 1: build a max-heap bottom-up (Floyd's method), O(n).
// Phase 2: repeatedly swap the root (largest) with the last element of the
//          shrinking heap and restore the heap property, O(n lg n).
//
// Complexity:  O(n lg n) in best (distinct keys), average and worst cases.
// Properties:  in place, NOT stable.

#include <utility>   // std::swap

// Sift data[root] down within the heap data[0..last] until the max-heap
// property holds again for that subtree. (File-local helper.)
static void moveDown(long data[], long root, long last) {
    long child;
    while ((child = 2 * root + 1) <= last) {      // left child exists
        if (child < last && data[child] < data[child + 1])
            child++;                              // pick the larger child
        if (!(data[root] < data[child]))
            break;                                // heap property satisfied
        std::swap(data[root], data[child]);
        root = child;
    }
}

void heapsort(long data[], long n) {
    if (n < 2) return;
    // Phase 1: build the heap, starting from the last non-leaf node
    for (long i = n / 2 - 1; i >= 0; --i)
        moveDown(data, i, n - 1);
    // Phase 2: move the largest item to its final spot, shrink the heap
    for (long i = n - 1; i >= 1; --i) {
        std::swap(data[0], data[i]);
        moveDown(data, 0, i - 1);
    }
}
