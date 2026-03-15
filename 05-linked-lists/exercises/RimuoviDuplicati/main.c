#include "no_dups.h"
#include <stdlib.h>

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    int v[] = { 0, 0, 2, 2, 4, 5 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item* list = ListCreateFromVector(v, v_size);
    ListWriteStdout(list);

    list = RemoveDuplicates(list);
    ListWriteStdout(list);

    ListDelete(list);

    return EXIT_SUCCESS;
}