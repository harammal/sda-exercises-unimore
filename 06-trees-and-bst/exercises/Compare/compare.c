#include "tree.h"

bool TreeAreIdentical(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}

	return ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) == 0 && 
		TreeAreIdentical(TreeLeft(t1), TreeLeft(t2)) && 
		TreeAreIdentical(TreeRight(t1), TreeRight(t2));
}