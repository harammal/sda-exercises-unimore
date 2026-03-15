#include "self.h"

Item* SelfOrganizingFind(Item* i, const ElemType* e) {
	if (i == NULL || e == NULL || ElemCompare(ListGetHeadValue(i), e) == 0) {
		return i;
	}

	Item* prev = i;
	Item* curr = i;
	bool find = false;

	while (!ListIsEmpty(curr->next)) {
		prev = curr;
		curr = ListGetTail(curr);

		if (ElemCompare(ListGetHeadValue(curr), e) == 0) {
			prev->next = curr->next;
			curr->next = i;
			find = true;

			break;
		}
	}

	if (find) {
		return curr;
	}
	else {
		return i;
	}
}