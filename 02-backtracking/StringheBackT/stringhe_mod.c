#include <stdio.h>
#include <stdlib.h>

void BacktrackStrModRec(int n, int k, int i, char* vcurr) {

	if (i == n) {
		printf("{ ");
		for (int s = 0; s < n; s++) {
			printf("%c", vcurr[s]);
		}
		printf(" }, ");

		return;
	}

	for (int j = 'a'; j < (k + 'a'); j++) {
		vcurr[i] = j;
		BacktrackStrModRec(n, k, i + 1, vcurr);
	}
}

void BacktrackStrMod(int n, int k) {
	if (n <= 0 || n > 26) {
		return 1;
	}

	char* vcurr = malloc(n);

	BacktrackStrModRec(n, k, 0, vcurr);

	free(vcurr);
}