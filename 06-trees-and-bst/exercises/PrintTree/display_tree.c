#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <string.h>

static void DisplayTreeRec(const Node* n, const char* prefix, bool hasSibling) {
    // Se il nodo è NULL
    if (n == NULL) {
        // Stampiamo "NULL" solo se il nodo ha un fratello
        if (hasSibling) {
            printf("%s+-- NULL\n", prefix);
        }
        return;
    }

    // Stampa il prefisso e il valore del nodo
    printf("%s+-- ", prefix);
    ElemWriteStdout(&n->value);
    printf("\n");

    // Costruisci il nuovo prefisso per i figli
    char newPrefix[256];
    strcpy(newPrefix, prefix);
    // Se il genitore ha un figlio destro, il sinistro non è l'ultimo
    if (n->right != NULL) {
        strcat(newPrefix, "+   ");
    }
    else {
        strcat(newPrefix, "    ");
    }

    // Il figlio sinistro ha un fratello se il destro esiste
    bool leftHasSibling = (n->right != NULL);
    DisplayTreeRec(n->left, newPrefix, leftHasSibling);

    // Il figlio destro ha un fratello se il sinistro esiste
    bool rightHasSibling = (n->left != NULL);
    DisplayTreeRec(n->right, newPrefix, rightHasSibling);
}

extern void DisplayTree(const Node* t) {
    // Caso base: albero vuoto
    if (t == NULL) {
        printf("NULL\n");
        return;
    }

    // Stampa il valore della radice senza prefisso
    ElemWriteStdout(&t->value);
    printf("\n");

    // Inizializza il prefisso vuoto per i figli
    char prefix[256] = "";

    // Il figlio sinistro ha un fratello se il destro esiste
    bool leftHasSibling = (t->right != NULL);
    DisplayTreeRec(t->left, prefix, leftHasSibling);

    // Il figlio destro ha un fratello se il sinistro esiste
    bool rightHasSibling = (t->left != NULL);
    DisplayTreeRec(t->right, prefix, rightHasSibling);
}