#include "list.h"

int Length(Item* list) {
	int len = 0;
	for (; !ListIsEmpty(list); list = ListGetTail(list)) {
		len++;
	}
	return len;
}

Item* Split(Item* list) {
	if (ListIsEmpty(list)) {
		return list;
	}
	int len = Length(list);
	if (len % 2 == 0) {
		len = (len / 2) - 1;
	}
	else {
		len /= 2;
	}

	for (int i = 0; i < len; i++) {
		list = ListGetTail(list);
	}
	Item* tmp = list->next;
	list->next = NULL;

	return tmp;
}