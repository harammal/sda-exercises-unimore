#include "cycle_len.h"

int main(void) {

	ElemType v[] = { 0, 1, 2, 3 };
	Item* list = ListCreateEmpty();

	for (int i = 0; i < 4; ++i) {
		list = ListInsertBack(list, v + i);
	}

	list->next->next->next->next = list->next;

	printf("Lunghezza Ciclo: %d\n", CycleLength(list));

	return 0;
}