#include "sum_dlist.h"
#include <stdlib.h>

Item* DListCreateFromVector(const ElemType* v, size_t v_size) {
    Item* list = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = DListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    ElemType e1[] = { 9, 5, 4 };
    Item* list1 = DListCreateFromVector(e1, sizeof(e1) / sizeof(ElemType));
    ElemType e2[] = { 6, 9 };
    Item* list2 = DListCreateFromVector(e2, sizeof(e2) / sizeof(ElemType));

    DListWriteStdout(list1);
    DListWriteStdout(list2);

    Item* sum = DListSum(list1, list2);
    DListWriteStdout(sum);

    DListDelete(list1);
    DListDelete(list2);
    DListDelete(sum);

    return 0;
}