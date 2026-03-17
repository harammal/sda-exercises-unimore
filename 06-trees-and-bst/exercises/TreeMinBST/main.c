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

extern const ElemType* BstTreeMin(const Node* n);
extern const ElemType* TreeMin(const Node* n);

int main(void) {
    int v[] = { 6, 1, 8, 1, 3, 7, 9};
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    tree = TreeCreateFromVector(v, v_size);

    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);

    //const ElemType *min1 = BstTreeMin(tree);
    const ElemType *min2 = TreeMin(tree);

    //printf("\nMin: %d\n", *min1);
    printf("\nMin: %d\n", *min2);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}