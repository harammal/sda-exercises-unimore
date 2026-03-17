#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

extern const Node* Successore(const Node* t, const Node* n);

int main(void) {
    // Foglie
    Node* n5 = TreeCreateRoot(&(int) { 5 }, NULL, NULL);
    Node* n9b = TreeCreateRoot(&(int) { 9 }, NULL, NULL);
    Node* n14 = TreeCreateRoot(&(int) { 14 }, NULL, NULL);
    Node* n15 = TreeCreateRoot(&(int) { 15 }, NULL, n9b); // 9 come figlio destro
    Node* n12 = TreeCreateRoot(&(int) { 12 }, NULL, NULL);
    Node* n11 = TreeCreateRoot(&(int) { 11 }, NULL, NULL);
    Node* n8 = TreeCreateRoot(&(int) { 8 }, NULL, NULL);
    Node* n7 = TreeCreateRoot(&(int) { 7 }, NULL, NULL);
    Node* n24 = TreeCreateRoot(&(int) { 24 }, n5, NULL); // 5 come figlio sinistro
    Node* n22 = TreeCreateRoot(&(int) { 22 }, NULL, NULL);

    // Livello intermedio
    Node* n13 = TreeCreateRoot(&(int) { 13 }, n22, n24);
    Node* n6 = TreeCreateRoot(&(int) { 6 }, n7, n8);
    Node* n10 = TreeCreateRoot(&(int) { 10 }, n11, n12);
    Node* n23 = TreeCreateRoot(&(int) { 23 }, n15, n14);

    // Secondo livello
    Node* n9 = TreeCreateRoot(&(int) { 9 }, n13, n6);
    Node* n17 = TreeCreateRoot(&(int) { 17 }, n10, n23);

    // Radice
    Node* tree = TreeCreateRoot(&(int) { 0 }, n9, n17);

    // Visualizza gli alberi
    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);

    Node* succ = Successore(tree, n9);
    printf("\nSuccessore: ");

    if (TreeIsEmpty(succ)) {
        printf("NULL\n");
    }
    else {
        ElemWrite(TreeGetRootValue(succ), stdout);
        printf("\nIndirizzo: %p\n", succ);
    }

    TreeDelete(tree);

    return EXIT_SUCCESS;
}