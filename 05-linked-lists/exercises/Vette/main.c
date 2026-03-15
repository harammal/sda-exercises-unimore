#include "list.h"

extern int ContaVette(const Item* i);

int main(void) {

	ElemType v[] = { 7, 2, 5, 5, 4};
	Item* list = ListCreateEmpty();

	for (int i = 0; i < 5; ++i) {
		list = ListInsertBack(list, v + i);
	}

	// [7, 2, 5, 5, 4] = 3 vette {7, 5'', 4}

	int cnt = ContaVette(list);
	printf("Numero vette: %d\n", cnt);

	return 0;
}