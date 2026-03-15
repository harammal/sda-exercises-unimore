#include "list.h"
#include <stdio.h>

extern int ListLenghtIte(const Item* i);
extern int ListLenghtRec(const Item* i);

int main(void) {

	ElemType v[] = { 1, 2, 3, 4, 5 };
	Item* list = ListCreateEmpty();

	printf("Len Lista vuota: %d", ListLenghtIte(list));

	for (int i = 0; i < 5; ++i) {
		list = ListInsertBack(list, v + i);
	}

	printf("\n\n");
	ListWriteStdout(list);

	printf("\nLen Ierativa: %d", ListLenghtIte(list));
	printf("\nLen Ricorsiva: %d", ListLenghtRec(list));
	printf("\n");

	ListDelete(list);

	return 0;
}