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

extern bool TreeAreIdentical(const Node* t1, const Node* t2);

int main(void) {
    int v[] = { 4, 3, 7, 0, 2, 5, 8 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree1 = TreeCreateEmpty();
    Node* tree2 = TreeCreateEmpty();

    tree1 = TreeCreateFromVector(v, v_size);
    tree2 = TreeCreateFromVector(v, v_size);

    TreeWriteStdoutPreOrder(tree1);
    TreeWriteStdoutPreOrder(tree2);

    bool ris = TreeAreIdentical(tree1, tree2);
    printf("\nRis: %d\n", ris);

    TreeDelete(tree1);
    TreeDelete(tree2);

    return EXIT_SUCCESS;
}