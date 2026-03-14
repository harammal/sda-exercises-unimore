#include <stdio.h>

void BacktrackSubset(int n, int i, int vcurr[], int* nsol) {
    if (i == n) { // Caso base: ho completato una soluzione
        printf("%d: ", *nsol); // Numero della soluzione
        (*nsol)++; // Incrementa il conteggio delle soluzioni

        // Stampa il sottoinsieme rappresentato
        for (int j = 0; j < n; j++) {
            printf("%d", vcurr[j]);
        }

		printf("\n");
		return;
	}

	//for (int j = 0; j < 2; j++) {
	//	vcurr[i] = j; // Scelta del valore j tra 0 (non prendo) e 1 (prendo)
	//				  // per il passo i (da 0 a n-1)
	//	BacktrackSubset(n, i + 1, vcurr, nsol);
	//}

	vcurr[i] = 0;
	BacktrackSubset(n, i + 1, vcurr, nsol);
	vcurr[i] = 1;
	BacktrackSubset(n, i + 1, vcurr, nsol);
}