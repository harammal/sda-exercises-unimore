#include "list.h"

int ContaVette(const Item* i) {
	if (ListIsEmpty(i)) {
		return 0;
	}

	int cnt = 0;

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		int max = ElemCopy(&tmp->value);
		bool vetta = true;

		for (const Item* pseudo = tmp; !ListIsEmpty(pseudo->next); pseudo = ListGetTail(pseudo)) {
			if (ElemCompare(&max, ListGetHeadValue(pseudo->next)) <= 0) {
				vetta = false;
				break;
			}
		}
		if (vetta) {
			cnt++;
		}
	}

	return cnt;
}