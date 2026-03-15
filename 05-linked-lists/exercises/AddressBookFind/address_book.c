#include "list.h"
#include <string.h>

const ElemType* Find(const Item* i, const char* name) {
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (strcmp((tmp->value).name, name) == 0) {
			return &tmp->value;
		}
	}
	return NULL;
}