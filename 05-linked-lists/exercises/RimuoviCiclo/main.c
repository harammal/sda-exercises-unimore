#include "no_cycle.h"

int main(void) {

	ElemType v[] = { 0, 1, 2, 3 };
	Item* list = ListCreateEmpty();

	for (int i = 0; i < 4; ++i) {
		list = ListInsertBack(list, v + i);
	}

	list->next->next->next->next = list->next;

	RemoveCycle(list);

	ListWriteStdout(list);
	ListDelete(list);

	return 0;
}