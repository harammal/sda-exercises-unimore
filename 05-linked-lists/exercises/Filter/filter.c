// MODIFICA DIRETTA DELLA LISTA (MIA VERSIONE)

#include "list.h"
#include <stdlib.h>

Item* Filter(Item* i, ElemType e) {
	if (i == NULL) {
		return NULL;
	}

	Item head = { .next = i };
	Item* prev = &head;
	Item* curr = i;

	while (!ListIsEmpty(curr)) {
		if (ElemCompare(ListGetHeadValue(curr), &e) >= 0) {

			if (prev == &head) {
				prev->next = curr->next;

				Item* to_delete = curr;
				i = ListGetTail(i);
				curr = i;

				ElemDelete(&to_delete->value);
				free(to_delete);
			}
			else {
				prev->next = curr->next;

				Item* to_delete = curr;
				curr = ListGetTail(curr);

				ElemDelete(&to_delete->value);
				free(to_delete);
			}
		}
		else {
			prev = ListGetTail(prev);
			curr = ListGetTail(curr);
		}
	}
	return i;
}