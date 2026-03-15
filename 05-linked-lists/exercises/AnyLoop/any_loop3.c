// ANY LOOP LEPRE E TARTARUGA

#include "list.h"

bool AnyLoop(const Item* i) {
	if (ListIsEmpty(i)) {
		return false;
	}

	Item* tart = i;
	Item* lepre = i;

	while (ListIsEmpty(lepre) && ListIsEmpty(ListGetTail(lepre))) {
		tart = tart->next;
		lepre = lepre->next->next;

		if (tart == lepre) {
			return true;
		}
	}
	return false;
}