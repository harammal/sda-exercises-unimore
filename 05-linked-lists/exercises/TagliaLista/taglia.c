#include "list.h"
#include <stdlib.h>

int ListLenght(Item* i) {
	int len = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		len++;
	}
	return len;
}

Item* Taglia(Item* i, int n) {
	int len = ListLenght(i);
	if (n < 0 || n >= len) {
		return i;
	}
	if (len == 0 || n == 0) {
		ListDelete(i);
		return ListCreateEmpty();
	}

	Item* tmp = i;
	
	for (int j = 0; j < n; ++j) {
		if (j == n - 1) {
			ListDelete(ListGetTail(tmp));
			tmp->next = NULL;
			break;
		}

		tmp = ListGetTail(tmp);
	}

	return i;
}