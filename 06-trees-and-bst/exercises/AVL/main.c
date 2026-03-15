#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

extern bool TreeIsBalanced(const Node* t);

int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5 };

    Node* tree = TreeCreateRoot(&e[2],
        TreeCreateRoot(&e[1], NULL, NULL),
        TreeCreateRoot(&e[4], NULL,
            TreeCreateRoot(&e[5], NULL, NULL)));

    TreeWriteStdoutPreOrder(tree);

    bool ris = TreeIsBalanced(tree);
    printf("Ris: %d", ris);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}