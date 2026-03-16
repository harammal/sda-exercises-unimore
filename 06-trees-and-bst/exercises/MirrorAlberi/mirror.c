#include "tree.h"
#include <stdbool.h>

bool IsMirror(const Node* left, const Node* right) {
	if (TreeIsEmpty(left) && TreeIsEmpty(right)) {
		return true;
	}
	if (TreeIsEmpty(left) || TreeIsEmpty(right)) {
		return false;
	}
	if (ElemCompare(TreeGetRootValue(left), TreeGetRootValue(right)) != 0) {
		return false;
	}

	return IsMirror(TreeLeft(left), TreeRight(right)) && IsMirror(TreeRight(left), TreeLeft(right));
}

bool TreeIsMirror(const Node* t) {
	if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
		return true;
	}
	
	return IsMirror(TreeLeft(t), TreeRight(t));;
}