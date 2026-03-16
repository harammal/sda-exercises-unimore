#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"

Node* TreeReadRec(FILE* f) {
	ElemType c;
	int ret = fscanf(f, " %c", &c);

	if (ret != 1) {
		return TreeCreateEmpty();
	}

	if (c == '.') {
		fscanf(f, " %c", &c);
		return TreeCreateRoot(&c, NULL, NULL);
	}

	Node* left = TreeReadRec(f);
	Node* right = TreeReadRec(f);

	return TreeCreateRoot(&c, left, right);
}

Node* TreeRead(const char* filename) {
	if (filename == NULL) {
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	Node* tree = TreeReadRec(f);

	fclose(f);

	return tree;
}