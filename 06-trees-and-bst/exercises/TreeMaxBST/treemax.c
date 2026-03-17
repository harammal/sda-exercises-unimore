#include "tree.h"

// BST
extern const ElemType* BstTreeMax(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}

	if (TreeIsEmpty(TreeRight(n))) {
		return TreeGetRootValue(n);
	}

	return BstTreeMax(TreeRight(n));
}

// NON BST
extern const ElemType* TreeMax(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType *max = TreeGetRootValue(n);

	const ElemType* left = TreeMax(TreeLeft(n));
	if (!TreeIsEmpty(TreeLeft(n)) && ElemCompare(left, max) > 0) {
		max = left;
	}

	const ElemType* right = TreeMax(TreeRight(n));
	if (!TreeIsEmpty(TreeRight(n)) && ElemCompare(right, max) > 0) {
		max = right;
	}

	return max;
}