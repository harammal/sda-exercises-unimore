#include "list.h"
#include <stdlib.h>

extern Item* Differenza(const Item* i1, const Item* i2);

Item* ListCreateFromVector(const ElemType* e, int e_size) {
    Item* n = ListCreateEmpty();
    for (int i = 0; i < e_size; ++i) {
        n = ListInsertBack(n, &e[i]);
    }
    return n;
}

int main(void) {
    ElemType e1[] = { '7', '1', '0', '1'};
    Item *list1 = ListCreateFromVector(e1, sizeof(e1) / sizeof(ElemType));
    ElemType e2[] = { '3', '2', '4' };
    Item* list2 = ListCreateFromVector(e2, sizeof(e2) / sizeof(ElemType));

    ListWriteStdout(list1);
    ListWriteStdout(list2);

    Item* diff = Differenza(list1, list2);
    ListWriteStdout(diff);

    ListDelete(list1);
    ListDelete(list2);
    ListDelete(diff);

    return 0;
}