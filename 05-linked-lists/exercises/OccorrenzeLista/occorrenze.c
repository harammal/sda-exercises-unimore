#include "list.h"

int ListOccorrenze(const Item* i, const ElemType* e) {
	int cont = 0;

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), e) == 0) {
			cont++;
		}
	}

	return cont;
}