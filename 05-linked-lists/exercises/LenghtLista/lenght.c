#include "list.h"

int ListLenghtIte(const Item* i) {
	int len = 0;
	
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		len++;
	}
	return len;
}

int ListLenghtRec(const Item* i) {
	if (ListIsEmpty(i)) {
		return 0;
	}
	
	return 1 + ListLenghtRec(ListGetTail(i));
}