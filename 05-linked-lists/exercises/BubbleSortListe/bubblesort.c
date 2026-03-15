#include "list.h"
#include <stdlib.h>

int Len(Item* list) {
	int len = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		len++;
	}
	return len;
}

Item* BubbleSort(Item* list) {
	if (ListIsEmpty(list)) {
		return ListCreateEmpty();
	}

	Item head = { .next = list };

	size_t dim = Len(list);
	bool done = false;

	while (!done) {

		done = true;
		Item* prev = &head;
		Item* curr = list;

		for (size_t j = 0; j < dim && !ListIsEmpty(curr->next); j++) {

			Item* foll = curr->next;
			Item* follfoll = foll->next;

			if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(curr->next)) > 0) {
				prev->next = foll;
				foll->next = curr;
				curr->next = follfoll;

				prev = foll;
				done = false;
			}
			else {
				prev = curr;
				curr = foll;
			}
		}
		dim--;
	}

	return head.next;
}