#include <stdlib.h>
#include <stdio.h>

extern double TopKImpact(const double* impacts, size_t impact_size, size_t k);

int main(void) {
	double v[] = { 6.000000, 3.000000, 1.000000, 4.000000, 12.000000, 24.000000 };

	double media = TopKImpact(v, 6, 1);

	printf("\nMedia: %f\n", media);

	return 0;
}