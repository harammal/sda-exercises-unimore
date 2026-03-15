// ANY LOOP PUNTATORI A TESTA E CURR

#include "list.h"

bool AnyLoop(const Item* i) {
	if (ListIsEmpty(i)) {
		return false;
	}

	Item* head = i;
	Item* curr = i;

	while (!ListIsEmpty(i)) {
		Item* tmp = head;

		while (tmp != curr) {
			if (tmp == curr->next) {
				return true;
			}
			tmp = ListGetTail(tmp);
		}
		
		curr = ListGetTail(curr);
	}

	return false;
}