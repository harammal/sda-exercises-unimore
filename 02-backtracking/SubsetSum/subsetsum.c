#include <stdio.h>

void BacktrackSomma(int n, int i, int vcurr[], int w[], int obiettivo,
	int sommacurr, int rimanenza, int* nsol) {
	if (sommacurr == obiettivo) { // stampa soluzione
		printf("%d) ",
			*nsol);
		(*nsol)++;
		for (int j = 0;j < i;j++) {
			printf("%d ", vcurr[j]);
		}
		for (int j = i;j < n;j++) {
			printf("0 "); }
				printf("\n");
			return;
		}
		if (i == n) return;
		rimanenza -= w[i];
		if ((sommacurr + rimanenza >= obiettivo) &&
			(i == n - 1 || (i < n - 1 && sommacurr + w[i + 1] <= obiettivo))) {
			vcurr[i] = 0;
			BacktrackSomma(n, i + 1, vcurr, w, obiettivo, sommacurr,
				rimanenza, nsol);
		}
		if (sommacurr + w[i] <= obiettivo) {
			vcurr[i] = 1;
			BacktrackSomma(n, i + 1, vcurr, w, obiettivo, sommacurr + w[i],
				rimanenza, nsol);
		}
	}