#include <stdio.h>
#include <stdlib.h>

void BacktrackStrRec(int n, int i, char *vcurr) {

	if (i == n) {
		printf("{ ");
		for (int s = 0; s < n; s++) {
			printf("%c", vcurr[s]);
		}
		printf(" }, ");

		return;
	}

	for (int j = 'a'; j < (n + 'a'); j++) {
		vcurr[i] = j;
		BacktrackStrRec(n, i + 1, vcurr);
	}
}

void BacktrackStr(int n) {
	if (n <= 0 || n > 26) {
		return 1;
	}

	char* vcurr = malloc(n);

	BacktrackStrRec(n, 0, vcurr);

	free(vcurr);
}