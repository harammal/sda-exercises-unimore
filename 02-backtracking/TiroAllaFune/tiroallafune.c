#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void Tiroallafune(int n, int *v, int dim1, int dim2, int* vcurr, int i, int *vbest, int mindiff, bool *usati) {

	if (i == n) {
		int sum1 = 0, sum2 = 0;
		for (int s = 0; s < dim1; s++) {
			sum1 += v[s];
		}
		for (int s = dim1; s < dim2; s++) {
			sum2 += v[s];
		}

		int diff = abs(sum1 - sum2);
		if (diff <= mindiff) {
			mindiff = diff;
			for (int c = 0; c < n; c++) {
				vbest[c] = vcurr[c];
			}
		}

		return;
	}

	for (int j = 0; j < n; j++) {
		if (!usati[j]) {
			vcurr[i] = v[j];
			usati[j] = true;

			Tiroallafune(n, v, dim1, dim2, vcurr, i + 1, vbest, mindiff, usati);

			usati[j] = false;
		}	
	}
}

int main(int argc, char** argv) {
	if (argc < 1) {
		return 1;
	}

	int n = argc - 1;
	int* v = malloc(n * sizeof(int));
	char* endptr;
	for (int i = 0; i < n; i++) {
		v[i] = strtol(argv[i + 1], &endptr, 10);
		if (*endptr != 0) {
			return 1;
		}
	}

	int dim1 = n / 2, dim2 = n - (n / 2);
	int* vcurr = malloc(n * sizeof(int));
	int* vbest = malloc(n * sizeof(int));
	bool* usati = calloc(n, sizeof(bool));

	Tiroallafune(n, v, dim1, dim2, vcurr, 0, vbest, INT_MAX, usati);

	printf("{ ");
	for (int i = 0; i < dim1; i++) {
		printf("%d ", vbest[i]);
	}
	printf("}, ");

	printf("{ ");
	for (int i = dim1; i < dim2; i++) {
		printf("%d ", vbest[i]);
	}
	printf(" }");

	free(vcurr);
	free(vbest);

	return 0;
}