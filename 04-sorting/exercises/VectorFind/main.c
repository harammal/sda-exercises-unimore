#include "vettore.h"
#include <stdio.h>

void PushBack(Vector* v, const ElemType* e) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, sizeof(ElemType) * v->capacity);
    }

    v->data[v->size] = ElemCopy(e);
    (v->size)++;
}


int main(void) {

    Vector v = { .capacity = 1, .size = 0,
                 .data = malloc(sizeof(ElemType)) };

    ElemType s[] = { {.size = 8,  .data = "fratello"},
                   {.size = 5,  .data = "mamma"},
                   {.size = 5, .data = "mamma"},
                   {.size = 4,  .data = "papà"},
    };

    for (int i = 0; i < 4; ++i) {
        PushBack(&v, s + i);
    }
    /*int data[] = { 4, 5, 5, 5, 7, 8 };
    Vector v = { .capacity = 6, .size = 6, .data = data };*/

    int pos = VectorFind(&v, v.data + 2);
    printf("Pos: %d\n", pos);

    return 0;
}
