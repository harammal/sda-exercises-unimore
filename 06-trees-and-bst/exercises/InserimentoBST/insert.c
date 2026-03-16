#include "tree.h"

Node* BstInsert(const ElemType* e, Node* n) {
    if (TreeIsEmpty(n)) {
        return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
    }

    Node* root = n;

    while (1) {
        if (ElemCompare(e, TreeGetRootValue(n)) < 0) {
            if (TreeIsEmpty(TreeLeft(n))) {
                n->left = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
                break;
            }
            else {
                n = TreeLeft(n);
            }
        }
        else {
            if (TreeIsEmpty(TreeRight(n))) {
                n->right = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
                break;
            }
            else {
                n = TreeRight(n);
            }
        }
    }

    return root;
}

Node* BstInsertRecTC(const ElemType* e, Node* n, Node *root) {
    if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
        if (TreeIsEmpty(TreeLeft(n))) {
            n->left = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
        }
        else {
            return BstInsertRecTC(e, TreeLeft(n), root);
        }
    }
    else {
        if (TreeIsEmpty(TreeRight(n))) {
            n->right = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
        }
        else {
            return BstInsertRecTC(e, TreeRight(n), root);
        }
    }

    return root;
}

Node* BstInsertRec(const ElemType* e, Node* n) {
    if (TreeIsEmpty(n)) {
        return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
    }

    return BstInsertRecTC(e, n, n);
}