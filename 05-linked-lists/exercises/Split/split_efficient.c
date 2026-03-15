#include "list.h"

Item* Split_Eff(Item* list) {
	if (ListIsEmpty(list)) {
		return list;
	}

	Item* slow = list;
	Item* fast = list;

	while (ListGetTail(fast) && ListGetTail(ListGetTail(fast))) {
		slow = slow->next;
		fast = fast->next->next;
	}
	Item* tmp = slow->next;
	slow->next = NULL;

	return tmp;
}