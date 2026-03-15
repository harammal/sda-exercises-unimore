#include "list.h"

extern Item* Filter(Item* i, ElemType e);

int main(void) {

	ElemType v[] = { 4, 4, 3, 2, 1};
	Item* list = ListCreateEmpty();

	for (int i = 0; i < 5; ++i) {
		list = ListInsertBack(list, v + i);
	}

	ListWriteStdout(list);
	printf("\n");

	list = Filter(list, 4);
	ListWriteStdout(list);

	ListDelete(list);

	return 0;
}