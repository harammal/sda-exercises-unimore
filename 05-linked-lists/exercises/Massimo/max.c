#include "list.h"
#include <stdlib.h>

const ElemType* MaxElement(const Item* i) {
	if (i == NULL) {
		return NULL;
	}

	const ElemType* max = ListGetHeadValue(i);

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		const ElemType* val = ListGetHeadValue(tmp);

		if (ElemCompare(val, max) > 0) {
			max = val;
		}
	}
	
	return max;
}