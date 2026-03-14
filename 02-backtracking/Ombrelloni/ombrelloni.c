#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void OmbrelloniRec(int k, int n, bool *vcurr, int i, int *nsol, int cnt) {

	if (cnt == k) {

		for (int j = 0; j < n - 1; ++j) {
			if ((vcurr[j] == 1) && (vcurr[j + 1] == 1)) {
				return;
			}
		}

		(*nsol)++;
		printf("%4d)", *nsol);
		for (int j = 0; j < n; ++j) {
			printf(" %d", vcurr[j]);
		}
		printf("\n");
		return;
	}

	if (i == n) {
		return;
	}

	vcurr[i] = 0;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol, cnt);
	vcurr[i] = 1;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol, cnt + 1);
	vcurr[i] = 0;
}

int Ombrelloni(int k, int n) {

	if (k < 0 || n < 0) {
		return 0;
	}

	bool* vcurr = malloc(sizeof(bool) * n);
	int nsol = 0;
	
	OmbrelloniRec(k, n, vcurr, 0, &nsol, 0);

	free(vcurr);

	if (nsol == 0) {
		return 0;
	}

	return nsol;
}
