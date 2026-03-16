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

extern void TreeCountNodes(const Node* t, int* internal, int* external);

int main(void) {
    int v[] = { 0, 1, 1, 4, 2, 2, 4};
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    tree = TreeCreateFromVector(v, v_size);

    TreeWriteStdoutPreOrder(tree);

    int internal, external;
    TreeCountNodes(tree, &internal, &external);

    printf("\nNodi Interni: %d\nNodi Esterni: %d\n", internal, external);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}