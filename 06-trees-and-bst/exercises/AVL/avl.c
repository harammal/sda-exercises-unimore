#include "tree.h"
#include <stdlib.h>
#include <math.h>

void HeightRec(const Node* n, int i, int* h) {
	if (TreeIsEmpty(n)) {
		return;
	}
	
	if (TreeIsLeaf(n)) {
		if (i > *h) {
			*h = i;
		}
		return;
	}

	HeightRec(TreeLeft(n), i + 1, h);
	HeightRec(TreeRight(n), i + 1, h);
}

int Height(const Node* n) {
	int h = -1;
	HeightRec(n, 0, &h);

	return h;
}

int GetBalanceCoeff(const Node* n) {
	if (TreeIsEmpty(n)) {
		return 0;
	}

	return Height(TreeLeft(n)) - Height(TreeRight(n));
}

void TreeIsBalancedRec(const Node* t, bool *ris) {
	if (TreeIsEmpty(t)) {
		return;
	}

	if (abs(GetBalanceCoeff(t)) <= 1) {
		TreeIsBalancedRec(TreeLeft(t), ris);
		TreeIsBalancedRec(TreeRight(t), ris);
	}
	else {
		*ris = false;
		return;
	}
}

bool TreeIsBalanced(const Node* t) {
	bool ris = true;
	TreeIsBalancedRec(t, &ris);
	
	return ris;
}