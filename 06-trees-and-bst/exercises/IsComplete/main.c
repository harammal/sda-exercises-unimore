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

extern bool IsComplete(const Node* t);

int main(void) {
    /*int v[] = { 6, 2, 3, 4, 5 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    tree = TreeCreateFromVector(v, v_size);*/

    Node* n4 = TreeCreateRoot(&(int) { 4 }, NULL, NULL);
    Node* n6 = TreeCreateRoot(&(int) { 6 }, NULL, NULL);
    Node* n2 = TreeCreateRoot(&(int) { 2 }, n4, NULL);    // solo figlio sinistro
    Node* n3 = TreeCreateRoot(&(int) { 3 }, NULL, n6);    // solo figlio destro
    Node* tree = TreeCreateRoot(&(int) { 1 }, n2, n3);

    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);

    bool ris = IsComplete(tree);
    printf("\nRis: %d \n", ris);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}