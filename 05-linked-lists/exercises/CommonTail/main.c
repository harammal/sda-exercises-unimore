#include "list.h"

extern const Item* CommonTail(const Item* i1, const Item* i2);

int main(void) {

	ElemType v1[] = { 0, 1, 2, 3, 4};
	ElemType e = 6;

	Item* list1 = ListCreateEmpty();
	Item* list2 = ListCreateEmpty();
	
	for (int i = 0; i < 5; ++i) {
		list1 = ListInsertBack(list1, v1 + i);
	}

	list2 = ListInsertBack(list2, &e);
	list2->next = list1->next->next;

	ListWriteStdout(list1);
	ListWriteStdout(list2);

	Item* common = CommonTail(list1, list2);
	printf("\nCoda comune: ");
	ListWriteStdout(common);

	free(list1);
	free(list2);

	return 0;
}