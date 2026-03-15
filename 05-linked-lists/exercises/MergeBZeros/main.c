#include "merge.h"

int main(void) {
	const ElemType v[6] = { 1, 0, 3, 4, 0, 6 };
	Item* list = ListCreateEmpty();

	for (int i = 0; i < 6; ++i) {
		list = ListInsertBack(list, v + i);
	}
	ListWriteStdout(list);

	MergeInBetweenZeros(list);
	ListWriteStdout(list);

	ListDelete(list);

	return 0;
}