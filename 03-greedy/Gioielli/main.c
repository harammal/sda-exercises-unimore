#include <stdlib.h>

#include "gioielli.h"

int main(void) {

    size_t ret_size;
    Gioiello *g;
    g = CompraGioielli("gioielli_1.txt", 121, &ret_size);
    free(g);

    g = CompraGioielli("gioielli_1.txt", 130, &ret_size);
    free(g);
    
    g = CompraGioielli("gioielli_2.txt", 121, &ret_size);
    free(g);
    
    g = CompraGioielli("gioielli_2.txt", 200, &ret_size);
    free(g);
    
    g = CompraGioielli("gioielli_3.txt", 121, &ret_size);
    free(g);
    
    g = CompraGioielli("gioielli_3.txt", 200, &ret_size);
    free(g);

    return 0;
}

