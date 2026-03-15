#include "shift.h"

int Lenght(Item* list) {
	int len = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		len++;
	}
	return len;
}

Item* ShiftN(Item* list, size_t n) {
	int len = Lenght(list);
	if (ListIsEmpty(list) || len == 1) {
		return list;
	}

	else if (n >= len) {
			Item* tmp = list;
			while (!ListIsEmpty(tmp->next)) {
				tmp = ListGetTail(tmp);
			}
			tmp->next = list;

			return list;
		}

	else {
		Item* first = list -> next;
		Item* curr = list;

		for (int i = 0; i < n; ++i) {
			Item* next = curr->next;

			curr->next = next->next;
			next->next = curr;
			
		}

		first->next = list;

		return first;
	}
}