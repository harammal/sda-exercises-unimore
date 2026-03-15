#include "merge.h"

Item* MergeInBetween(Item* i1, Item* i2, int l, int r) {
	if (i1 == NULL) {
		return NULL;
	}

	Item* prev = NULL;
	Item* start_cut = i1;

	for (int i = 0; i < l; i++) {
		prev = start_cut;					// Salvo la parte iniziale da tenere (A)
		start_cut = ListGetTail(start_cut); // Salvo la posizione inziale di taglio (B)
	}

	Item* end_cut = NULL;
	Item* after = start_cut;

	for (int i = l; i <= r; i++) {
		end_cut = after;					// end_cut è il prev di after
		after = ListGetTail(after);			// Salvo la posizione finale di taglio (C) e la parte finale da tenere (D)
	}

	end_cut->next = NULL;					// Delimito la parte da tagliare (start_cut - end_cut)

	ListDelete(start_cut);					// Elimino la parte da tagliare (BC)			

	if (i2 == NULL) {
		if (l != 0) {
			prev->next = after;
		}
		else {
			i1 = after;
		}
	}
	else {
		if (l != 0) {
			prev->next = i2;
		}
		else {
			i1 = i2;						// Collego la parte inziale con la parte finale (AD)
		}

		Item* tmp = i2;
		while (!ListIsEmpty(ListGetTail(tmp))) {
			tmp = ListGetTail(tmp);
		}
		tmp->next = after;
	}

	return i1;
}