#include "tree.h"

// BST
extern const ElemType* BstTreeMin(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}

	if (TreeIsEmpty(TreeLeft(n))) {
		return TreeGetRootValue(n);
	}

	return BstTreeMin(TreeLeft(n));
}

// NON BST
extern const ElemType* TreeMin(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType *min = TreeGetRootValue(n);

	const ElemType* left = TreeMin(TreeLeft(n));
	if (!TreeIsEmpty(TreeLeft(n)) && ElemCompare(left, min) <= 0) {
		min = left;
	}

	const ElemType* right = TreeMin(TreeRight(n));
	if (!TreeIsEmpty(TreeRight(n)) && ElemCompare(right, min) <= 0) {
		min = right;
	}

	return min;
}