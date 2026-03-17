#include "tree.h"

void Ricerca(const Node* t, const Node* n, const Node** succ) {
	if (TreeIsEmpty(t)) {
		return;
	}

	if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(n)) > 0) {
		if (TreeIsEmpty(*succ)) {
			*succ = t;
		}
		else if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(*succ)) < 0) {
			*succ = t;
		}
	}

	Ricerca(TreeLeft(t), n, succ);
	Ricerca(TreeRight(t), n, succ);
}

const Node* Successore(const Node* t, const Node* n) {
	if (TreeIsEmpty(t) || n == NULL) {
		return NULL;
	}

	const Node* succ = NULL;
	Ricerca(t, n, &succ);

	return succ;
}