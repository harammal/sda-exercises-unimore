// COPIA DEGLI ELEMENTI MINORI DI e IN UN'ALTRA LISTA

#include "list.h"
#include <stdlib.h>

Item* Filter(Item* i, ElemType e) {
	Item* r = ListCreateEmpty();

	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetTail(tmp), &e) < 0) {
			r = ListInsertBack(r, ListGetHeadValue(tmp));
		}
	}

	ListDelete(i);
	return r;
}