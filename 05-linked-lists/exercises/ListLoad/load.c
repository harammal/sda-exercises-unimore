#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdlib.h>

Item* ListLoad(const char* filename) {
	if (filename == NULL) {
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	Item* list = ListCreateEmpty();
	ElemType e;
	int ret = 0;

	while (1) {
		ret = fscanf(f, "%d", &e);
		if (ret != 1) {
			break;
		}
		list = ListInsertHead(&e, list);
	}

	fclose(f);

	return list;
}