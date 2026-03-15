#include "list.h"
#include <stdlib.h>
#include <stdio.h>

extern Item* ListLoad(const char* filename);
extern const ElemType* MaxElement(const Item* i);

int main(void) {

	Item* list = ListLoad("data_00.txt");
	ListWriteStdout(list);

	const ElemType *max = MaxElement(list);
	printf("%d", *max);

	ListDelete(list);

	return 0;
}