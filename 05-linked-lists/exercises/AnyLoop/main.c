#include "list.h"

extern bool AnyLoop(const Item* i);

int main(void) {

	ElemType v[] = { 0, 1, 2, 3 };
	Item* list = ListCreateEmpty();

	for (int i = 0; i < 4; ++i) {
		list = ListInsertBack(list, v + i);
	}

	list->next->next->next->next = list->next;
	bool ris = AnyLoop(list);

	if (!ris) {
		ListWriteStdout(list);
		ListDelete(list);
	}
	else {
		printf("Ciclo presente\n");
	}

	return 0;
}