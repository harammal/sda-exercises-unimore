#include "vettore.h"
#include <stdio.h>

int main(void) {
    ElemType data[] = { 3, 6, 1, 8, 3, 5 };
    Vector v = { 6, 6, &data };

    VectorSort(&v);

    for (int i = 0; i < v.size; ++i) {
        printf("%d ", v.data[i]);
    }

    return 0;
}