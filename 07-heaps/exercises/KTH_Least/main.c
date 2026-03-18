#include "minheap.h"
#include <stdlib.h>

extern ElemType KthLeast(const Heap* h, int k);

int main(void) {

    Heap h = { .data = malloc(5 * sizeof(ElemType)), .size = 5 };
    h.data[0] = 1;
    h.data[1] = 2;
    h.data[2] = 3;
    h.data[3] = 4;
    h.data[4] = 5;

    HeapWriteStdout(&h);

    ElemType e = KthLeast(&h, 2);

    free(h.data);

    return 0;
}