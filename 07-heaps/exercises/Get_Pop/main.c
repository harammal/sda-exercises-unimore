#include "get_pop.h"

int main(void) {

    Heap h = { .data = malloc(5 * sizeof(ElemType)), .size = 5 };
    h.data[0] = 1;
    h.data[1] = 2;
    h.data[2] = 3;
    h.data[3] = 4;
    h.data[4] = 5;

    HeapWriteStdout(&h);

    ElemType* e = Get(&h);
    printf("\nGet: %d\n", *e);

    Pop(&h);
    HeapWriteStdout(&h);

    free(h.data);

    return 0;
}