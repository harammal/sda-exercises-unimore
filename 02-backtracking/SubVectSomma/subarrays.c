#include <stdlib.h>

void OptimalSubarrayRec(const int* v, size_t n, size_t start, int* max_sum) {
    if (start == n) {
        return;
    }

    int sum = 0;
    for (size_t end = start; end < n; ++end) {
        sum += v[end];

        // Aggiorno max_sum solo se, fino a quel punto (elementi contigui), la sum attuale è maggiore
        if (sum > *max_sum) {
            *max_sum = sum;
        }
    }

    // Prossimo indice di inizio sottovettore
    OptimalSubarrayRec(v, n, start + 1, max_sum);
}

int OptimalSubarray(const int* v, size_t n) {
    if (n == 0 || v == NULL) {
        return 0;
    }

    int max_sum = 0;
    OptimalSubarrayRec(v, n, 0, &max_sum);
    return max_sum;
}

//int main(void) {
//
//    int v[] = { 1, 2, 1, -100, 5, 6 };
//
//    int somma = OptimalSubarray(v, 6);
//
//    return somma;
//}