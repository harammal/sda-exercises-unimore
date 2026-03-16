#include "tree.h"

size_t CountNodes(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}

	return 1 + CountNodes(TreeLeft(t)) + CountNodes(TreeRight(t));
}

void Visit(const Node* t, size_t n, size_t i, bool *ris) {
	if (TreeIsEmpty(t)) {
		return;
	}
	
	if (i >= n) {
		*ris = false;
		return;
	}

	Visit(TreeLeft(t), n, 2 * i + 1, ris);
	Visit(TreeRight(t), n, 2 * i + 2, ris);
}

bool IsComplete(const Node* t) {
	if (TreeIsEmpty(t)) {
		return true;
	}

	size_t n = CountNodes(t);

	bool ris = true;
	Visit(t, n, 0, &ris);

	return ris;
}