#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

bool IsIn(const Item* i, const ElemType* e) {
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), e) == 0) {
			return true;
		}
	}
	return false;
}

Item* Diff(const Item* i1, const Item* i2) {
	Item* list = ListCreateEmpty();

	for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (!IsIn(i2, ListGetHeadValue(tmp))) {
			list = ListInsertBack(list, ListGetHeadValue(tmp));
		}
	}
	return list;
}

Item* DiffNoRep(const Item* i1, const Item* i2) {
	Item* list = ListCreateEmpty();

	for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (!IsIn(i2, ListGetHeadValue(tmp)) && !IsIn(list, ListGetHeadValue(tmp))) {
			list = ListInsertBack(list, ListGetHeadValue(tmp));
		}
	}
	return list;
}