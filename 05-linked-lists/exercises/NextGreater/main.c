#include "next_greater.h"

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    int v[] = { 2, 3, 1, 4, 7, 2 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item* list = ListCreateFromVector(v, v_size);

    size_t size = 0;
    ElemType* answer = NextGreater(list, &size);

    ListDelete(list);

    return EXIT_SUCCESS;
}