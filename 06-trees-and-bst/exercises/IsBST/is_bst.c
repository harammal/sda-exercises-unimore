#include "tree.h"

static bool IsBSTRec(const Node* t, const ElemType* min, const ElemType* max) {
    if (TreeIsEmpty(t)) {
        return true;
    }

    const ElemType* val = TreeGetRootValue(t);

    if ((min != NULL && ElemCompare(val, min) <= 0) ||
        (max != NULL && ElemCompare(val, max) > 0)) {
        return false;
    }

    return IsBSTRec(TreeLeft(t), min, val) &&
        IsBSTRec(TreeRight(t), val, max);
}

bool IsBST(Node* t) {
    return IsBSTRec(t, NULL, NULL);
}
