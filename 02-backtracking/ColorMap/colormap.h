#ifndef COLORMAP_H
#define COLORMAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct SquareMatrix {
	size_t side;
	bool* data;
};
typedef struct SquareMatrix SquareMatrix;

extern int ColorMap(const SquareMatrix* m, const char* c);

#endif // COLORMAP_H