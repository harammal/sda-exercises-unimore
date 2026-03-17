#include "tree.h"
#include <stdlib.h>

Node* InsertBST(const ElemType* e, Node* tree, Node* root) {
	if (ElemCompare(e, TreeGetRootValue(tree)) < 0) {
		if (TreeIsEmpty(TreeLeft(tree))) {
			tree->left = TreeCreateRoot(e, NULL, NULL);
		}
		else {
			return InsertBST(e, TreeLeft(tree), root);
		}
	}
	else if (ElemCompare(e, TreeGetRootValue(tree)) > 0) {
		if (TreeIsEmpty(TreeRight(tree))) {
			tree->right = TreeCreateRoot(e, NULL, NULL);
		}
		else {
			return InsertBST(e, TreeRight(tree), root);
		}
	}

	return root;
}

Node* Vector2BST(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size <= 0) {
		return TreeCreateEmpty();
	}

	Node* tree = TreeCreateRoot(v, NULL, NULL);
	
	for (size_t i = 1; i < v_size; ++i) {
		tree = InsertBST(v + i, tree, tree);
	}

	return tree;
}