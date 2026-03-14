#include <stdlib.h>
#include <string.h>

int Compare(const void *a, const void* b) {
	return (*(double*)b - *(double*)a);
}

double TopKImpact(const double* impacts, size_t impact_size, size_t k) {
	if (k < 1 || k > impact_size) {
		return 0.0;
	}

	double* vect = malloc(impact_size * sizeof(double));
	memcpy(vect, impacts, impact_size * sizeof(double));

	qsort(vect, impact_size, sizeof(double), Compare);

	double media = 0;
	for (size_t i = 0; i < k; ++i) {
		media += vect[i];
	}

	media /= k;
	
	free(vect);

	return media;
}