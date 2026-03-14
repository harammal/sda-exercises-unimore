#include <stdlib.h>
#include <stdio.h>

int Steps(int n);

int main(void) {
	return Steps(3);
}

void StepsRec(int n, int* vcurr, int i, int* nsol, int scalini) {

	if (scalini == n) {
		printf("[");

		for (int j = 0; j < i - 1; ++j) {
			printf("%d, ", vcurr[j]);

		}
		printf("%d]", vcurr[i - 1]);
		if (i != 1) {
			printf(", ");
		}

		(*nsol)++;
		return;
	}

	for (int j = 1; j <= 3; ++j) {
		if (scalini + j <= n) {
			vcurr[i] = j;

			StepsRec(n, vcurr, i + 1, nsol, scalini + j);
		}
	}
}

int Steps(int n) {
	if (n <= 0) {
		return 0;
	}

	int nsol = 0;
	int *vcurr = malloc(n * sizeof(int));

	StepsRec(n, vcurr, 0, &nsol, 0);

	return nsol;
}