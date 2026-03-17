#include "vector_tree.h"

int main(void) {
    int v1[] = { 0, 1, 2, 3, 4, 5 };
    size_t v_size1 = sizeof(v1) / sizeof(int);

    int v2[] = { 999, 0, 1, 2, 3, 4, 5 };
    size_t v_size2 = sizeof(v1) / sizeof(int);

    Node *tree1 = Vector2Tree(v1, v_size1, kZeroBased);
    Node* tree2 = Vector2Tree(v2, v_size2, kOneBased);

    TreeWriteStdoutPreOrder(tree1);
    TreeWriteStdoutPreOrder(tree2);

    TreeDelete(tree1);
    TreeDelete(tree2);

    return EXIT_SUCCESS;
}