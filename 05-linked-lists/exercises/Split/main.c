#include "list.h"

extern Item* Split(Item* list);
extern Item* Split_Eff(Item* list);

int main(void) {

	ElemType v[] = { 0, 1, 2, 3, 4};
	Item* list1 = ListCreateEmpty();
	Item* list2 = ListCreateEmpty();

	for (int i = 0; i < 5; ++i) {
		list1 = ListInsertBack(list1, v + i);
		list2 = ListInsertBack(list2, v + i);
	}
	printf("Lista originale: ");
	ListWriteStdout(list1);

	Item* list_split = Split(list1);
	printf("\nPrima Parte: ");
	ListWriteStdout(list1);
	printf("Seconda Parte: ");
	ListWriteStdout(list_split);

	Item* list_split_eff = Split_Eff(list2);
	printf("\nPrima Parte (Eff): ");
	ListWriteStdout(list2);
	printf("Seconda Parte (Eff): ");
	ListWriteStdout(list_split_eff);

	ListDelete(list1);
	ListDelete(list2);

	ListDelete(list_split);
	ListDelete(list_split_eff);

	return 0;
}