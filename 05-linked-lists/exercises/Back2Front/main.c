#include "list.h"
#include <stdlib.h>

extern void Back2Front(Item** i);

int main(void) {

	ElemType v[] = { 1, 2, 3, 4};

	Item* list = ListCreateEmpty();
	
	for (int i = 0; i < 4; ++i) {
		list = ListInsertBack(list, v + i);
	}
	printf("Lista originaria:\n");
	ListWriteStdout(list);

	Back2Front(&list);
	printf("\nUltimo elemento in testa:\n");
	ListWriteStdout(list);

	free(list);

	return 0;
}