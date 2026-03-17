#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"

void TreeWriteRec(const Node* t, int i, FILE *f) {
	if (TreeIsEmpty(t)) {
		return;
	}

	ElemType c = ElemCopy(TreeGetRootValue(t));

	if (TreeIsLeaf(t)) {
		fprintf(f, "%*s", 4 * i, "");
		fprintf(f, ".%c\n", c);
		return;
	}
	else {
		fprintf(f, "%*s", 4 * i, "");
		fprintf(f, "%c\n", c);

		TreeWriteRec(TreeLeft(t), i + 1, f);
		TreeWriteRec(TreeRight(t), i + 1, f);
	}
}

bool TreeWrite(const Node* t, const char* filename) {
	if (filename == NULL) {
		return false;
	}
	FILE* f = fopen(filename, "w");
	if (f == NULL) {
		return false;
	}

	TreeWriteRec(t, 0, f);

	fclose(f);

	return true;
}