#include "tree.h"

void TreeCountNodesRec(const Node* t, int* internal, int* external) {
	if (TreeIsEmpty(t)) {
		return;
	}

	if (TreeIsLeaf(t)) {
		(*external)++;
	}
	else if (!TreeIsLeaf(t)) {
		(*internal)++;
	}

	TreeCountNodes(TreeLeft(t), internal, external);
	TreeCountNodes(TreeRight(t), internal, external);
}

void TreeCountNodes(const Node* t, int* internal, int* external) {
	(*internal) = 0;
	(*external) = 0;

	TreeCountNodesRec(t, internal, external);
}