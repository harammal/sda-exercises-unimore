#include "list.h"

Item* Delete(Item* i, const char* name) {
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (strmp((tmp->value).name, name) == 0){
			ListD
		}
	}
	return i;
}