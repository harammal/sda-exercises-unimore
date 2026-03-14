#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void SubsetEqualRec(int n, int s, bool *vcurr, int *nsol, int i, int somma) {
	if (somma == s) {
		(*nsol)++;

		printf("{ ");
		for (int ind = 1; ind <= n; ind++) {
			if (vcurr[ind - 1]) {
				printf("%d ", ind);
			}
		}
		printf("}, ");
		return;
	}

	if (i == n) {
		return;
	}
	
	vcurr[i] = 0;
	SubsetEqualRec(n, s, vcurr, nsol, i + 1, somma);

	vcurr[i] = 1;
	SubsetEqualRec(n, s, vcurr, nsol, i + 1, somma + (i + 1));

	vcurr[i] = 0;
}

int SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0) {
		return 0;
	}

	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;

	SubsetEqualRec(n, s, vcurr, &nsol, 0, 0);
	free(vcurr);

	return nsol;
}