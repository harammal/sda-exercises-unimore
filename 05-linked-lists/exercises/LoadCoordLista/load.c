#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdlib.h>

Item* ListLoad(const char* filename) {
	if (filename == NULL) {
		return NULL;
	}

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return ListCreateEmpty();
	}

	Item* list = ListCreateEmpty();
	ElemType e;

	while (ElemRead(f, &e) == 2) {
		list = ListInsertHead(&e, list);
	}
	
	fclose(f);

	return list;
}