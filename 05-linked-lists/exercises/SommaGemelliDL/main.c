#include "dlgemelli.h"
#include <stdlib.h>
#include <stdio.h>

Item* DListCreateFromVector(const ElemType* v, size_t v_size) {
    Item* list = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = DListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    ElemType e[] = { 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 0, 2, 0, 0, 1 };
    Item* list = DListCreateFromVector(e, sizeof(e) / sizeof(ElemType));

    DListWriteStdout(list);

    int somma = SommaGemelli(list);
    printf("\nSomma massima: %i\n", somma);

    DListDelete(list);

    return 0;
}