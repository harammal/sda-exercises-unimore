#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

extern Node* Vector2BST(const ElemType* v, size_t v_size);

int main(void) {
    int v[] = { 8, 2, 4, 5, 2, 1, 9};
    size_t v_size = sizeof(v) / sizeof(int);

    Node *tree = Vector2BST(v, v_size);

    TreeWriteStdoutPreOrder(tree);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}