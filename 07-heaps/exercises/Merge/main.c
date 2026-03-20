#include "minheap.h"
#include <stdlib.h>

extern Heap* HeapMerge(const Heap* h1, const Heap* h2);

int main(void) {

    Heap h = { .data = malloc(5 * sizeof(ElemType)), .size = 5 };
    h.data[0] = 1;
    h.data[1] = 2;
    h.data[2] = 3;
    h.data[3] = 4;
    h.data[4] = 5;
    HeapWriteStdout(&h);

    Heap h2 = { .data = malloc(4 * sizeof(ElemType)), .size = 4 };
    h2.data[0] = 6;
    h2.data[1] = 7;
    h2.data[2] = 8;
    h2.data[3] = 9;
    HeapWriteStdout(&h2);

    Heap* h3 = HeapMerge(&h, &h2);
    HeapWriteStdout(h3);

    free(h.data);
    free(h2.data);
    HeapDelete(h3);

    return 0;
}