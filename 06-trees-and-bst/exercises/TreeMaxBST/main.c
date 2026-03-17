#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
    if (i >= (int)v_size) {
        return NULL;
    }

    Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
    Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

    return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
    return TreeCreateFromVectorRec(v, v_size, 0);
}

extern const ElemType* BstTreeMax(const Node* n);
extern const ElemType* TreeMax(const Node* n);

int main(void) {
    int v[] = { 6, 4, 9, 1, 3, 7, 9};
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    tree = TreeCreateFromVector(v, v_size);

    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);

    //const ElemType *max1 = BstTreeMax(tree);
    const ElemType *max2 = TreeMax(tree);

    //printf("\nMax: %d\n", *max1);
    printf("\nMax: %d\n", *max2);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}