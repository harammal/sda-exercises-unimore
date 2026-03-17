#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

extern int* RightView(const Node* t, size_t* size);

int main(void)
{
    {
        ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
        Node* t = TreeCreateRoot(&e[5],
            TreeCreateRoot(&e[2],
                TreeCreateRoot(&e[1], NULL, NULL),
                TreeCreateRoot(&e[3],
                    NULL,
                    TreeCreateRoot(&e[4], NULL, NULL))),
            TreeCreateRoot(&e[6], NULL, NULL));
        size_t size = 0;
        int* v = RightView(t, &size);
        
        free(v);
    }
    //{
    //    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    //    Node* t = TreeCreateRoot(&e[5],
    //        TreeCreateRoot(&e[2],
    //            TreeCreateRoot(&e[1], NULL, NULL),
    //            NULL),
    //        TreeCreateRoot(&e[6], NULL, NULL));
    //    // Chiamata a funzione
    //}
    //{
    //    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    //    Node* t = TreeCreateRoot(&e[3], TreeCreateRoot(&e[2], TreeCreateRoot(&e[1], TreeCreateRoot(&e[0], NULL, NULL), NULL), NULL), NULL);
    //    // Chiamata a funzione
    //}
    //{
    //    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
    //    Node* t = TreeCreateRoot(&e[12],
    //        TreeCreateRoot(&e[6],
    //            TreeCreateRoot(&e[5],
    //                TreeCreateRoot(&e[3],
    //                    NULL,
    //                    NULL),
    //                NULL),
    //            TreeCreateRoot(&e[9],
    //                TreeCreateRoot(&e[8], NULL, NULL),
    //                TreeCreateRoot(&e[10], NULL, NULL))),
    //        TreeCreateRoot(&e[15],
    //            TreeCreateRoot(&e[13], NULL, NULL),
    //            TreeCreateRoot(&e[18], NULL, NULL)));
    //    // Chiamata a funzione
    //}

    return 0;
}