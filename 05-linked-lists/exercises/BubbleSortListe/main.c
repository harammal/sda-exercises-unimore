#include "list.h"
#include <stdlib.h>

extern Item* BubbleSort(Item* list);

Item* ListCreateFromVector(const ElemType* e, int e_size) {
    Item* n = ListCreateEmpty();
    for (int i = 0; i < e_size; ++i) {
        n = ListInsertBack(n, &e[i]);
    }
    return n;
}

int main(void) {
    ElemType e1[] = { 3, 2, 1 };
    Item *list = ListCreateFromVector(e1, sizeof(e1) / sizeof(ElemType));

    ListWriteStdout(list);
    Item* ord = BubbleSort(list);
    ListWriteStdout(ord);

    ListDelete(ord);

    return 0;
}