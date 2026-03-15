#include "list.h"
#include <stdio.h>

extern int ListOccorrenze(const Item* i, const ElemType* e);

int main(void) {

	ElemType v[] = { 1, 2, 2, 2, 5 };
	Item* list = ListCreateEmpty();

	for (int i = 0; i < 5; ++i) {
		list = ListInsertBack(list, v + i);
	}

	ListWriteStdout(list);

	ElemType occ = 2;
	printf("\nOccorrenze 2: %d volte\n", ListOccorrenze(list, &occ));

	ListDelete(list);

	return 0;
}