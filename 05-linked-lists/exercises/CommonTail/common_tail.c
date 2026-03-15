#include "list.h"
#include <stdlib.h>

// ElemType v1[] = { 0, 1, 2, 3, 4 };
// ElemType v2[] = {    6, 2, 3, 4 };

const Item* CommonTail(const Item* i1, const Item* i2) {
	if (i1 == NULL || i2 == NULL) {
		return NULL;
	}

	for (; !ListIsEmpty(i1); i1 = ListGetTail(i1)) {
		for (const Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {

			if (i1 == tmp) {
				return i1;
			}
		}
	}

	return NULL;
}