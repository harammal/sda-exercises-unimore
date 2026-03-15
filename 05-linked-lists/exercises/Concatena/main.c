#include "concatena.h"

int main(void) {

	ElemType v1[] = { 0, 1, 2, 3};
	Item* list1 = ListCreateEmpty();

	ElemType v2[] = { 4, 5, 6, 7 };
	Item* list2 = ListCreateEmpty();

	for (int i = 0; i < 4; ++i) {
		list1 = ListInsertBack(list1, v1 + i);
		//list2 = ListInsertBack(list2, v2 + i);
	}

	printf("Lista 1: ");
	ListWriteStdout(list1);
	printf("Lista 2: ");
	ListWriteStdout(list2);

	Item* list3 = Concatena(list1, list2, kCopy);
	//list1 = Concatena(list1, list2, kNoCopy);

	//printf("\nLista Concatenata: ");
	//ListWriteStdout(list1);

	printf("\nLista Concatenata: ");
	ListWriteStdout(list3);

	ListDelete(list1);
	ListDelete(list2);
	ListDelete(list3);

	return 0;
}