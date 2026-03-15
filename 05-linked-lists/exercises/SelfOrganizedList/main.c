#include "self.h"

int main(void) {

	ElemType v[] = { 0, 1, 2, 3, 4 };
	Item* list = ListCreateEmpty();

	for (int i = 0; i < 5; ++i) {
		list = ListInsertBack(list, v + i);
	}
	ListWriteStdout(list);

	ElemType e = 5;

	list = SelfOrganizingFind(list, &e);
	ListWriteStdout(list);

	ListDelete(list);

	return 0;
}