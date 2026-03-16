#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

extern Node* TreePrune(Node* t, const ElemType* cut_value);

int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5 , 6, 7, 8};

    Node* tree = TreeCreateRoot(&e[2],
        TreeCreateRoot(&e[3], 
            TreeCreateRoot(&e[4], 
                TreeCreateRoot(&e[8], NULL, NULL), 
                TreeCreateRoot(&e[1], NULL, NULL)), 
            NULL),
        TreeCreateRoot(&e[7], NULL,
            TreeCreateRoot(&e[4],
                TreeCreateRoot(&e[0], NULL, NULL),
                TreeCreateRoot(&e[1], NULL, NULL))));

    TreeWriteStdoutPreOrder(tree);

    const ElemType cut_value = 4;
    tree = TreePrune(tree, &cut_value);

    TreeWriteStdoutPreOrder(tree);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}