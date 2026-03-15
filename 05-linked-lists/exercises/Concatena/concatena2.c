#include "concatena.h"

static Item* Copy(Item* i, enum ConcType c) {
	if (c == kNoCopy) {
		return i;
	}

	Item* r = ListCreateEmpty();
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		r = ListInsertBack(r, ListGetHeadValue(tmp));
	}
	return r;
}

Item* Concatena(Item* i1, Item* i2, enum ConcType c) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return NULL;
	}

	if (ListIsEmpty(i1)) {
		return Copy(i2, c);
	}

	if (ListIsEmpty(i2)) {
		return Copy(i1, c);
	}

	Item* tmp, * rhead;
	tmp = rhead = Copy(i1, c);

	while (!ListIsEmpty(ListGetTail(tmp))) {
		tmp = ListGetTail(tmp);
	}
	tmp->next = Copy(i2, c);

	return rhead;
}