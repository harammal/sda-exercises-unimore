#include "merge.h"

void MergeInBetweenZeros(Item* i) {
    if (i == NULL) return;

    Item* curr = i;

    while (!ListIsEmpty(curr)) {
        // Cerca il primo zero
        if (ElemCompare(ListGetHeadValue(curr), 0) == 0) {
            Item* start = curr;
            Item* prev = curr;
            curr = curr->next;

            int sum = 0;
            int count = 0;

            // Somma finché non trovi un altro zero (o fine lista)
            while (curr != NULL && ElemCompare(&curr->value, 0) != 0) {
                sum += curr->value;
                Item* tmp = curr;
                curr = curr->next;
                ElemDelete(&tmp->value);
                free(tmp);
                count++;
            }

            // Se trovato secondo zero e almeno un valore tra i due
            if (curr != NULL && count > 0) {
                // Inserisco il nodo con la somma
                Item* new_node = malloc(sizeof(Item));
                new_node->value = sum;
                new_node->next = curr;

                start->next = new_node;
            }
            else {
                // Nessuna somma valida, collego direttamente
                start->next = curr;
            }
        }
        else {
            curr = curr->next;
        }
    }
}