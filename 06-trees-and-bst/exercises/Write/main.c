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

extern bool TreeWrite(const Node* t, FILE* f);

int main(void) {  //  0    1    2    3    4    5    6
    ElemType e[] = { 'a', 'x', 'b', 'd', 'c', 's', 'u' };
    Node* tree = TreeCreateRoot(&e[0], 
        TreeCreateRoot(&e[1], NULL, NULL), 
        TreeCreateRoot(&e[2], 
            TreeCreateRoot(&e[3], 
                TreeCreateRoot(&e[5], NULL, NULL), 
                TreeCreateRoot(&e[6], NULL, NULL)), 
            TreeCreateRoot(&e[4], NULL, NULL)));

    TreeWriteStdoutPreOrder(tree);

    bool ris = TreeWrite(tree, "albero_01.txt");
    printf("Ris: %d", ris);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}