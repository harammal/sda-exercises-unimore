#include "list.h"
#include <stdlib.h>

void Back2Front(Item** i) {
	if (ListIsEmpty(*i) || ListIsEmpty(ListGetTail(*i))) {
		return;
	}

	Item* prev = NULL;
	Item* curr = (*i);
	
	while (!ListIsEmpty(ListGetTail(curr))) {
		prev = curr;
		curr = ListGetTail(curr);
	}
	curr->next = (*i);
	*i = curr;

	prev->next = NULL;

	return;
}
