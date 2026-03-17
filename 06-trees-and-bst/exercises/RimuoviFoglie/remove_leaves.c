#include "tree.h"

Node* RemoveLeaves(Node* t) {
	if (TreeIsEmpty(t)) {
		return t;
	}

	if (TreeIsLeaf(t)) {
		TreeDelete(t);
		return TreeCreateEmpty();
	}

	t->left = RemoveLeaves(TreeLeft(t));
	t->right = RemoveLeaves(TreeRight(t));

	return t;
}