#include "merge.h"

int main(void) {

	ElemType v1[] = { 5, 4, 8, 1};
	Item* list1 = ListCreateEmpty();

	ElemType v2[] = { 1, 2, 3, 4 };
	Item* list2 = ListCreateEmpty();

	for (int i = 0; i < 4; ++i) {
		list1 = ListInsertBack(list1, v1 + i);
	}
	ListWriteStdout(list1);

	for (int i = 0; i < 4; ++i) {
		list2 = ListInsertBack(list2, v2 + i);
	}
	ListWriteStdout(list2);

	list1 = MergeInBetween(list1, list2, 1, 2);
	printf("\nUnisci lista 2 nel mezzo di lista 1:\n");
	ListWriteStdout(list1);

	ListDelete(list1);

	return 0;
}