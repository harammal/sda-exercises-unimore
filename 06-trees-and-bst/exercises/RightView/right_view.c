#include "tree.h"
#include <stdlib.h>

static void TreeHeightRec(const Node* t, int* height, int i) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (TreeIsLeaf(t)) {
		if (i > *height) {
			*height = i;
		}
		return;
	}
	TreeHeightRec(TreeLeft(t), height, i + 1);
	TreeHeightRec(TreeRight(t), height, i + 1);
}

static int TreeHeight(const Node* t) {
	int height = -1;
	TreeHeightRec(t, &height, 0);
	return height;
}


static void PrintLevelRec(const Node* t, int level, int** v, size_t* size, size_t* cap, bool* one) {
	if (*one || TreeIsEmpty(t)) {
		return;
	}
	
	if (level == 0) {
		if (*cap == *size) {
			*cap *= 2;
			*v = realloc(*v, (*cap) * sizeof(int));
		}

		(*v)[*size] = ElemCopy(TreeGetRootValue(t));
		(*size)++;

		*one = true;
		return;
	}

	PrintLevelRec(TreeRight(t), level - 1, v, size, cap, one);
	PrintLevelRec(TreeLeft(t), level - 1, v, size, cap, one);
}

int* RightView(const Node* t, size_t* size) {
	if (TreeIsEmpty(t)) {
		*size = 0;
		return NULL;
	}
	
	int height = TreeHeight(t);

	size_t cap = 3;
	int* v = malloc(cap * sizeof(int));
	*size = 0;

	for (int i = 0; i <= height; ++i) {
		bool one = false;
		PrintLevelRec(t, i, &v, size, &cap, &one);
	}

	return v;
}