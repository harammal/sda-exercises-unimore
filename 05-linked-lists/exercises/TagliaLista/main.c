#include "list.h"
#include <stdio.h>

extern Item* Taglia(Item* i, int n);

int main(void) {

	ElemType v[] = { 0, 1, 2, 3 };
	Item* list = ListCreateEmpty();
	Item* out = ListCreateEmpty();

	for (int i = 0; i < 4; ++i) {
		list = ListInsertBack(list, v + i);
	}
	ListWriteStdout(list);

	out = Taglia(list, 2);
	ListWriteStdout(out);

	ListDelete(list);

	return 0;
}