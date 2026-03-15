#include "no_dups.h"
#include <stdbool.h>

bool IsIn(const Item* i, const ElemType *e) {
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), e) == 0) {
			return true;
		}
	}
	return false;
}

Item* RemoveDuplicates(const Item* i) {
	Item* list = ListCreateEmpty();

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (!IsIn(list, ListGetHeadValue(tmp))) {
			list = ListInsertBack(list, ListGetHeadValue(tmp));
		}
	}

	return list;
}
