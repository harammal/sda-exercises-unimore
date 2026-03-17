#include "vector_tree.h"

Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
    if (i >= (int)v_size || v[i] == INT_MAX) {
        return NULL;
    }

    Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
    Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

    const ElemType e = v[i];

    return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
    return TreeCreateFromVectorRec(v, v_size, 0);
}

Node* Vector2Tree(const ElemType* v, size_t v_size, enum TreeType type) {
    Node* tree = TreeCreateEmpty();

    if (type == kZeroBased) {
        tree = TreeCreateFromVector(v, v_size);
	}
    if (type == kOneBased) {
        tree = TreeCreateFromVector(v + 1, v_size + 1);
    }

    return tree;
}