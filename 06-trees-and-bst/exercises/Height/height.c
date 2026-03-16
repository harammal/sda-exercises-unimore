#include "tree.h"

void TreeHeightRec(const Node* t, int i, int *h) {
	if (TreeIsEmpty(t)) {
		return;
	}
	
	if (TreeIsLeaf(t)) {

		if (i > *h) {
			*h = i;
		}

		return;
	}

	TreeHeightRec(TreeLeft(t), i + 1, h);
	TreeHeightRec(TreeRight(t), i + 1, h);
}

int TreeHeight(const Node* t) {
	int h = -1;

	TreeHeightRec(t, 0, &h);

	return h;
}