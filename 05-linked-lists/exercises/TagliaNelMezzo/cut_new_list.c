#include "list.h"

extern int Length(Item* list);

Item* ListCutCopy(Item* list, int start, int end) {
	if (start >= end || ListIsEmpty(list)) {
		return list;
	}
	int len = Length(list);
	if (start >= len) {
		return list;
	}

	Item* new_list = ListCreateEmpty();

	Item* curr = list;

	for (int i = 0; i < start; i++) {
		new_list = ListInsertBack(new_list, &curr->value);		// Copio la parte iniziale della lista
		curr = ListGetTail(curr);
	}

	for (int i = start; i <= end && !ListIsEmpty(curr); i++) {
		curr = ListGetTail(curr);								// Itero la lista per saltare la parte da tagliare
	}

	if (end < len) {
		for (int i = end + 1; !ListIsEmpty(curr); i++) {
			new_list = ListInsertBack(new_list, &curr->value);	// Copio la parte finale della lista
			curr = ListGetTail(curr);
		}
	}

	return new_list;
}

void ListCut_NewList(Item** list, int start, int end) {
	Item* new_list = ListCutCopy(*list, start, end);
	ListDelete(*list);				// Libera la lista originale
	*list = new_list;				// Sostituzione del puntatore della vecchia lista
}									// (Ora la nuova testa è new_list)
