#include "sum_dlist.h"

Item* DListCopy(const Item* i) {
    Item* list_copy = DListCreateEmpty(); // Creo una lista vuota (NULL pointer)

    // Itero tutti gli elementi della lista da copiare
    for (; !DListIsEmpty(i); i = DListGetTail(i)) {
        // Aggiungo l'elemento corrente della lista di input alla nuova lista
        // usando la primitiva ListInsertBack(), la quale si occupa di allocare
        // opportunamente la memoria e aggiornare i puntatori!
        list_copy = DListInsertBack(list_copy, DListGetHeadValue(i));
    }

    return list_copy;
}

Item* DListSum(const Item* i1, const Item* i2) {
    if (DListIsEmpty(i1) && DListIsEmpty(i2)) {
        return DListCreateEmpty();
    }
    if (DListIsEmpty(i1)) {
        return DListCopy(i2);
    }
    if (DListIsEmpty(i2)) {
        return DListCopy(i1);
    }

    const Item* tmp1 = i1;
    const Item* tmp2 = i2;
    for (; !DListIsEmpty(tmp1->next); tmp1 = DListGetTail(tmp1)) {}
    for (; !DListIsEmpty(tmp2->next); tmp2 = DListGetTail(tmp2)) {}

    Item* somma = DListCreateEmpty();

    ElemType p = 0;
    while (!DListIsEmpty(tmp1) || !DListIsEmpty(tmp2)) {

        ElemType c1 = 0, c2 = 0, s = 0;

        if (!DListIsEmpty(tmp1)) {
            c1 = *DListGetHeadValue(tmp1);
        }
        if (!DListIsEmpty(tmp2)) {
            c2 = *DListGetHeadValue(tmp2);
        }

        c1 += p;
        p = 0;
        s = c1 + c2;
        if (s  >= 10) {
            p = 1;
            s -= 10;
        }

        somma = DListInsertHead(&s, somma);

        if (!DListIsEmpty(tmp1)) {
            tmp1 = DListGetPrev(tmp1);
        }
        if (!DListIsEmpty(tmp2)) {
            tmp2 = DListGetPrev(tmp2);
        }
    }

    if (p == 1) {
        somma = DListInsertHead(&p, somma);
    }

    return somma;
}