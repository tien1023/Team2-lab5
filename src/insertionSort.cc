// Insertion sort (ascending). Based on Drozdek, Ch. 9.1.1.
//
// Complexity:  best O(n) (already sorted)
//              average / worst O(n^2)

void insertionsort(long data[], long n) {
    for (long i = 1; i < n; i++) {
        long tmp = data[i];              // element to insert
        long j;
        for (j = i; j > 0 && tmp < data[j - 1]; j--)
            data[j] = data[j - 1]; // shift every larger element in data[0..i-1] one slot to the right
        data[j] = tmp; // drop it into its proper position
    }
}