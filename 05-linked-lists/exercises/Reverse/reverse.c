#include "reverse.h"

int ListLenght(Item* list) {
	int len = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		len++;
	}
	return len;
}

Item* Reverse(Item* list, int left) {
	int len = ListLenght(list);
	if (left >= len - 1) {
		return list;
	}

	if (left <= 0) {
		int i = 0;

		Item* prev = NULL;
		Item* curr = list;

		while (i <= len - 1) {			// reverse
			Item* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;

			i++;
		}

		return prev;
	}

	else {
		int i = 0;
		Item* first = list;
		while (i < left - 1) {			// itero fino a left - 1
			first = ListGetTail(first);
			i++;
		}
		// first  = curr - 1
		Item* curr = first->next;
		Item* prev = NULL;

		i = left;
		while (i <= len - 1) {			// reverse
			Item* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;

			i++;
		}

		first->next = prev;

		return list;
	}
}