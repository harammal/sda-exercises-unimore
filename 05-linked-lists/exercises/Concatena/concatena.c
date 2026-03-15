#include "concatena.h"

int Length(Item* i) {
	int len = 0;
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		len++;
	}
	return len;
}

Item* Concatena(Item* i1, Item* i2, enum ConcType c) {
	if (i1 == NULL && i2 == NULL) {
		return NULL;
	}
	int len1 = Length(i1), len2 = Length(i2);

	if (c == kCopy) {
		Item* i3 = ListCreateEmpty();

		if (i1 != NULL) {
			for (int j = 0; j < len1; ++j) {
				i3 = ListInsertBack(i3, i1);
				i1 = ListGetTail(i1);
			}
		}

		if (i2 != NULL) {
			for (int j = 0; j < len2; ++j) {
				i3 = ListInsertBack(i3, i2);
				i2 = ListGetTail(i2);
			}
		}

		return i3;
	}
	else if(c == kNoCopy){
		if (i1 == NULL) {
			return i2;
		}
		else if (i2 == NULL) {
			return i1;
		}

		Item* tmp = i1;
		for (int j = 0; j < len1 - 1; ++j) {
			tmp = ListGetTail(tmp);
		}
		tmp->next = i2;

		return i1;
	}

	return NULL;
}