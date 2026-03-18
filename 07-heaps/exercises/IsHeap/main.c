#include "minheap.h"
#include <stdlib.h>

extern bool IsHeap(const Heap* h);

int main(void) {

    Heap h = { .data = malloc(5 * sizeof(ElemType)), .size = 5 };
    h.data[0] = 6;
    h.data[1] = 2;
    h.data[2] = 3;
    h.data[3] = 4;
    h.data[4] = 5;

    HeapWriteStdout(&h);

    bool ris = IsHeap(&h);
    printf("\nRis: %d\n", ris);

    free(h.data);

    return 0;
}