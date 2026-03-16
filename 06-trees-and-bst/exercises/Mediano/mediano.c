#include "tree.h"
#include <float.h>

static int TreeCountNodes(const Node* t) {
	if (t == NULL) {
		return 0;
	}

	return 1 + TreeCountNodes(TreeLeft(t)) + TreeCountCount(TreeRight(t));
}

static void GetNodeValueByIndex(const Node* t, int n, int* i, ElemType* v, bool* done) {
	if (TreeIsEmpty(t) || *done) {
		return;
	}

	GetNodeValueByIndex(TreeLeft(t), n, i, v, done);
	(*i)++;

	if (n == *i) {
		*v = *TreeGetRootValue(t);
		*done = true;
		return;
	}

	GetNodeValueByIndex(TreeRight(t), n, i, v, done);
}

double Mediano(const Node* t) {
	if (t == NULL) {
		return DBL_MAX;
	}

	int nnodes = TreeCountNodes(t);

	ElemType v1, v2;
	int i;
	bool done;

	if (nnodes % 2 == 0) {
		i = 0;
		done = false;
		GetNodeValueByIndex(TreeLeft(t), nnodes/2 +1, &i, &v1, &done);

		i = 0;
		done = false;
		GetNodeValueByIndex(TreeLeft(t), nnodes / 2, &i, &v2, &done);

		return (v1 + v2) / 2.;
	}
	else {
		i = 0;
		done = false;
		GetNodeValueByIndex(TreeLeft(t), nnodes / 2 + 1, &i, &v1, &done);

		return (double)v1;
	}
}