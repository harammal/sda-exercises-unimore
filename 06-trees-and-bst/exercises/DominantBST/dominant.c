#include "tree.h"

int CountDominant(const Node* t) {
    if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
        return 0;
    }

    const Node* left = TreeLeft(t);
    const Node* right = TreeRight(t);

    ElemType somma = 0;

    if (!TreeIsEmpty(left)) {
        somma += *TreeGetRootValue(left);
    }
    if (!TreeIsEmpty(right)) {
        somma += *TreeGetRootValue(right);
    }

    if (ElemCompare(TreeGetRootValue(t), &somma) > 0) {
        return 1 + CountDominant(TreeLeft(t)) + CountDominant(TreeRight(t));
    }
    else {
        return CountDominant(TreeLeft(t)) + CountDominant(TreeRight(t));
    }
}