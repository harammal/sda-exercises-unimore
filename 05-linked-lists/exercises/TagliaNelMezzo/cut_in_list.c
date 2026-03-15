#include "list.h"

int Length(Item* list) {
	int len = 0;
	for (; !ListIsEmpty(list); list = ListGetTail(list)) {
		len++;
	}
	return len;
}

Item* ListCut_InList(Item* list, int start, int end) {
	int len = Length(list);
	if (start < 0) {
		start = 0;
	}
	if (end >= len) {
		end = len - 1;
	}										// Controlli di Ripristino dei valori per evitare controlli nei cicli
	
	if (start >= len || start > end || ListIsEmpty(list)) {
		return list;
	}

	// ABCD --(Taglio BC)-> AD
	Item* prev = NULL;
	Item* start_cut = list;

	for (int i = 0; i < start; i++) {
		prev = start_cut;					// Salvo la parte iniziale da tenere (A)
		start_cut = ListGetTail(start_cut); // Salvo la posizione inziale di taglio (B)
	}

	Item* end_cut = NULL;
	Item* after = start_cut;

	for (int i = start; i <= end; i++) {
		end_cut = after;					// end_cut è il prev di after
		after = ListGetTail(after);			// Salvo la posizione finale di taglio (C) e la parte finale da tenere (D)
	}

	if (end_cut != NULL) {
		end_cut->next = NULL;				// Delimito la parte da tagliare (start_cut - end_cut)
	}

	ListDelete(start_cut);					// Elimino la parte da tagliare (BC)			

	if (start != 0) {
		prev->next = after;
	}
	else {
		list = after;						// Collego la parte inziale con la parte finale (AD)
	}

	return list;
}